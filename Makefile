SUBDIRS =JournalLib Program

DOMAKE = for dir in $(SUBDIRS); do $(MAKE) -C $$dir $@; done

all : $(SUBDIRS)

$(SUBDIRS) :
	$(MAKE) -C $@

clean :
	$(DOMAKE)

test :
	$(DOMAKE)

rebuild :
	$(DOMAKE)

run :
	$(MAKE) -C Program $@

docs :
	$(DOMAKE)

.PHONY: all clean test $(SUBDIRS)
