DISPLAY_APP := lvgl8.0_knob
ifeq ($(DISPLAY_APP), lvgl8.0)
SUBDIRS := global \
		   app-server \
		   audio-server \
		   display-server/lvgl8.0 \
		   master-server \
		   monitor \
		   burn-server \
		   upgrade-server \
		   wifi-server\
		   web-server
else
SUBDIRS := global \
		   app-server \
		   audio-server \
		   display-server/lvgl8.0_knob \
		   master-server \
		   monitor \
		   burn-server \
		   upgrade-server \
		   wifi-server\
		   web-server
endif

all:
	@for subdir in $(SUBDIRS); do \
		$(MAKE) -C $$subdir/ $@; \
	done;


clean:
	@for subdir in $(SUBDIRS); do \
		$(MAKE) -C $$subdir/ $@; \
	done;
