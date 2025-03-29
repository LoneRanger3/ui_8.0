/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-08-14 16:57:12
 * @LastEditTime: 2023-09-05 17:18:21
 */
#ifndef JSONINTERFACE_H
#define JSONINTERFACE_H
#include "json-c/json_object.h"
#include "json-c/json_tokener.h"
#include "json-c/json_util.h"
#include <string>
using namespace std;

class JsonObject
{
public:
    JsonObject()
    {
        jsonobj=json_object_new_object();
    }

    JsonObject(struct json_object *obj)
    {
        jsonobj = nullptr;
        if(obj){
            jsonobj = json_object_get(obj);
        }
    }

    JsonObject(const JsonObject& jobj)
    {
        jsonobj = json_object_get(jobj.jsonobj);
    }

    JsonObject& operator=(const JsonObject& jobj)
    {
        if(this == &jobj)
            return *this;
        if(jsonobj != nullptr)
        {
            json_object_put(jsonobj);
        }
        jsonobj = json_object_get(jobj.jsonobj);
        return *this;
    }

    ~JsonObject()
    {
        if(jsonobj){
            json_object_put(jsonobj);
        }
    }

    json_object *get(){return jsonobj;}

    bool operator!=(JsonObject& jobj)
    {
        string ori;
        if(jsonobj) ori = json_object_to_json_string(jsonobj);
        string now;
        if(jobj.get()) now = json_object_to_json_string(jobj.get());
        return (ori == now)? false:true;
    }

private:
    struct json_object *jsonobj;
};

class JsonInter
{
public:
    static int add(struct json_object *obj, const string key,int val)
    {
        return json_object_object_add(obj,key.c_str(),json_object_new_int(val));
    }

    static int add(struct json_object *obj, const string key,uint32_t val)
    {
        return json_object_object_add(obj,key.c_str(),json_object_new_int(val));
    }

    static int add(struct json_object *obj, const string key,int64_t val)
    {
        return json_object_object_add(obj,key.c_str(),json_object_new_int64(val));
    }

    static int add(struct json_object *obj, const string key,uint64_t val)
    {
        return json_object_object_add(obj,key.c_str(),json_object_new_uint64(val));
    }
    
    static int add(struct json_object *obj, const string key,double val)
    {
        return json_object_object_add(obj,key.c_str(),json_object_new_double(val));
    }

    static int add(struct json_object *obj, const string key,string val)
    {
        return json_object_object_add(obj,key.c_str(),json_object_new_string(val.c_str()));
    }

    static int add(struct json_object *obj, const string key,bool val)
    {
        return json_object_object_add(obj,key.c_str(),json_object_new_boolean(val));
    }

    static int add(struct json_object *obj, const string key,struct json_object * val)
    {
        return json_object_object_add(obj,key.c_str(),val);
    }

    static int add(struct json_object *obj, const string key,JsonObject &val)
    {
        return json_object_object_add(obj,key.c_str(),json_object_get(val.get()));
    }    

    static int getintdirect(struct json_object *obj,int err = 0)
    {
        if(obj!=nullptr && json_object_is_type(obj,json_type_int))
        {
            return json_object_get_int(obj);
        }
        return err;
    }

    static int64_t getint64direct(struct json_object *obj,int64_t err = 0)
    {
        if(obj!=nullptr && json_object_is_type(obj,json_type_int))
        {
            return json_object_get_int64(obj);
        }
        return err;
    }

    static string getstringdirect(struct json_object *obj)
    {
        if(obj!=nullptr && json_object_is_type(obj,json_type_string))
        {
            return json_object_get_string(obj);
        }
        return "";
    }
    
    static bool getbooldirect(struct json_object *obj,bool err = false)
    {
        if(obj!=nullptr && json_object_is_type(obj,json_type_boolean))
        {
            return json_object_get_boolean(obj);
        }
        return err;
    }
    
    static double getdoubledirect(struct json_object *obj,double err = 0)
    {
        if(obj!=nullptr && json_object_is_type(obj,json_type_double))
        {
            return json_object_get_double(obj);
        }
        return err;
    }
    
    static int getint(struct json_object *obj, const string key, int err = 0)
    {
        if(obj == nullptr) return err;
        json_object *targ = json_object_object_get(obj, key.c_str());
        if(targ!=nullptr && json_object_is_type(targ,json_type_int))
        {
            return json_object_get_int(targ);
        }
        return err;
    }

    static int64_t getint64(struct json_object *obj, const string key, int64_t err = 0)
    {
        if(obj == nullptr) return err;
        json_object *targ = json_object_object_get(obj, key.c_str());
        if(targ!=nullptr && json_object_is_type(targ,json_type_int))
        {
            return json_object_get_int64(targ);
        }
        return err;
    }

    static uint64_t getuint64(struct json_object *obj, const string key, uint64_t err = 0)
    {
        if(obj == nullptr) return err;
        json_object *targ = json_object_object_get(obj, key.c_str());
        if(targ!=nullptr && json_object_is_type(targ,json_type_int))
        {
            return json_object_get_uint64(targ);
        }
        return err;
    }

    static bool getbool(struct json_object *obj, const string key, bool err = false)
    {
        if(obj == nullptr) return err;
        json_object *targ = json_object_object_get(obj, key.c_str());
        if(targ!=nullptr && json_object_is_type(targ,json_type_boolean))
        {
            return json_object_get_boolean(targ);
        }
        return err;
    }

    static string getstring(struct json_object *obj, const string key)
    {
        if(obj == nullptr) return "";
        json_object *targ = json_object_object_get(obj, key.c_str());
        if(targ!=nullptr && json_object_is_type(targ,json_type_string))
        {
            return json_object_get_string(targ);
        }
        return "";
    }

    static double getdouble(struct json_object *obj, const string key, double err = 0)
    {
        if(obj == nullptr) return err;
        json_object *targ = json_object_object_get(obj, key.c_str());
        if(targ!=nullptr && json_object_is_type(targ,json_type_double))
        {
            return json_object_get_double(targ);
        }
        return err;
    }

    static struct json_object * getobject(struct json_object *obj, const string key)
    {
        if(obj == nullptr) return nullptr;
        json_object *targ = json_object_object_get(obj, key.c_str());
        if(targ!=nullptr && json_object_is_type(targ,json_type_object))
        {
            return targ;
        }
        return nullptr;
    }

    static struct json_object * getarray(struct json_object *obj, const string key)
    {
        if(obj == nullptr) return nullptr;
        json_object *targ = json_object_object_get(obj, key.c_str());
        if(targ!=nullptr && json_object_is_type(targ,json_type_array))
        {
            return targ;
        }
        return nullptr;
    }

    static void test()
    {
        json_object *test = json_object_new_object();
        add(test,"int",10);
        add(test,"int64",100);
        add(test,"string","nownn");
        add(test,"double",2.33333);
        
        printf("add over %s\n",json_object_to_json_string(test));
        printf("getint %d\n",getint(test,"int"));
        printf("getint64 %ld\n",getint64(test,"int64"));
        printf("getdouble %lf\n",getdouble(test,"double"));
        printf("getstring %s\n",getstring(test,"string").c_str());

        printf("getinterr %d\n",getint(test,"inte"));
        printf("getint64err %ld\n",getint64(test,"int64e"));
        printf("getdoubleerr %lf\n",getdouble(test,"doublee"));
        printf("getstringerr %s\n",getstring(test,"stringe").c_str());
        json_object_put(test);
    }
};



#endif