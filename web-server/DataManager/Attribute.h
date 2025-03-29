#pragma once
#include <string>
#include <iostream>
#include <sys/time.h>
#include <memory>
#include "global/Global.h"
#include "Base/JsonInter.h"

using namespace std;
#define INTERVAL_NO 0xffff
class Attribute
{
protected:
    string key;
    uint64_t start;
    int interval;
public:
    Attribute(const string &key,int interval):start(0)
    {
        this->key = key;
        this->interval = interval;
    }

    uint64_t getnow()
    {
        struct timeval st;
        gettimeofday(&st, NULL);
        return st.tv_sec;
    }

    virtual int getObj(struct json_object *obj) = 0;
    virtual int setToObj(struct json_object *obj,void *val) = 0;
    virtual int getTimeoutObj(struct json_object *obj) = 0;
};

template<class T>
class AttrAll:public Attribute
{
private:
    T t;
public:
    AttrAll(const string &key,const T &in,int interval):Attribute(key,interval)
    {
        t = in;
    }

    virtual int getObj(struct json_object *obj)
    {
        start = 0;
        return JsonInter::add(obj,key,t);
    }

    virtual int getTimeoutObj(struct json_object *obj)
    {
        if(start != 0 && (getnow() - start) > interval)
            return getObj(obj);
        return -1;
    }

    virtual int setToObj(struct json_object *obj,void *val)
    {
        if(t != *((T*)val))
        {
            t = *((T*)val);
            if(interval == 0)
            {
                if(obj) return JsonInter::add(obj,key,t);
            }else if(INTERVAL_NO == interval)
            {

            }else{
                if(!start)
                {
                    start = getnow();
                }
            }
        }
        return 1;
    }
};

typedef shared_ptr<Attribute> AttributePtr;
