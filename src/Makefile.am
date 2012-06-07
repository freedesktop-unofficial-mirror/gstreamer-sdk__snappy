NULL =

public_headers = \
		utils.h \
		user_interface.h \
		dlna.h \
		gst_engine.h \
		screensaver.h

c_sources = \
	utils.c \
	user_interface.c \
	dlna.c \
	gst_engine.c \
	screensaver.c \
	snappy.c

CLEANFILES =

bin_PROGRAMS = snappy

if OS_WIN32
  pkgdata_flags = -DSNAPPY_DATA_DIR="\"../share/snappy/\""
else
  pkgdata_flags = -DSNAPPY_DATA_DIR="\"$(pkgdatadir)\""
endif

snappy_SOURCES = $(c_sources)
snappy_CFLAGS = $(CLUTTER_CFLAGS) $(GSTREAMER_0_10_CFLAGS) $(GST_PBUTILS_CFLAGS) $(GST_INTERFACES_CFLAGS) $(CLUTTER_GST_CFLAGS) $(GIO_CFLAGS) $(XTEST_CFLAGS) $(pkgdata_flags)
snappy_LDADD = $(CLUTTER_LIBS) $(GSTREAMER_0_10_LIBS) $(GST_PBUTILS_LIBS) $(GST_INTERFACES_LIBS) $(CLUTTER_GST_LIBS) $(GIO_LIBS) $(XTEST_LIBS)

noinst_HEADERS = $(public_headers)
