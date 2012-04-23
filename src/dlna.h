/*
 * snappy - 0.2
 *
 * Copyright (C) 2011 Collabora Multimedia Ltd.
 * <luis.debethencourt@collabora.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#ifndef __DLNA_H__
#define __DLNA_H__

#include <gio/gio.h>
#include <glib-object.h>

#include "gst_engine.h"
#include "user_interface.h"

G_BEGIN_DECLS
#define MPRIS_BUS_NAME_PREFIX "org.mpris.MediaPlayer2"
#define MPRIS_OBJECT_NAME "/org/mpris/MediaPlayer2"
#define MPRIS_ROOT_INTERFACE "org.mpris.MediaPlayer2"
#define MPRIS_PLAYER_INTERFACE "org.mpris.MediaPlayer2.Player"
#define MPRIS_TRACKLIST_INTERFACE "org.mpris.MediaPlayer2.TrackList"
#define MPRIS_PLAYLISTS_INTERFACE "org.mpris.MediaPlayer2.Playlists"

typedef struct _SnappyMP SnappyMP;
struct _SnappyMP
{
  gchar *name;

  GDBusConnection *connection;
  GDBusNodeInfo *node_info;
  guint name_own_id;
  guint root_id;
  guint player_id;
  guint playlists_id;
  guint owner_id;

  int playlist_count;

  GHashTable *player_property_changes;
  GHashTable *playlist_property_changes;
  guint property_emit_id;

  gint64 last_elapsed;

  gchar *uri;

  GstEngine *engine;
  UserInterface *ui;
};

enum
{
  PROP_0,
  PROP_COUNT,
  PROP_NAME
};

enum
{
  OPEN_URI,
  LAST_SIGNAL
};

static guint mediaplayer_signals[LAST_SIGNAL] = { 0 };

// Declaration of non-static functions
gboolean load_dlna (SnappyMP * mp_obj);
gboolean close_dlna (SnappyMP * mp_obj);

void handle_method_call (GDBusConnection * connection,
    const gchar * sender,
    const gchar * object_path,
    const gchar * interface_name,
    const gchar * method_name,
    GVariant * parameters,
    GDBusMethodInvocation * invocation, SnappyMP * myobj);

GVariant *handle_get_property (GDBusConnection * connection,
    const gchar * sender,
    const gchar * object_path,
    const gchar * interface_name,
    const gchar * property_name, GError ** error, gpointer user_data);

gboolean handle_set_property (GDBusConnection * connection,
    const gchar * sender,
    const gchar * object_path,
    const gchar * interface_name,
    const gchar * property_name,
    GVariant * value, GError ** error, gpointer user_data);

void handle_root_method_call (GDBusConnection * connection,
    const char *sender,
    const char *object_path,
    const char *interface_name,
    const char *method_name,
    GVariant * parameters, GDBusMethodInvocation * invocation, SnappyMP * mp);

GVariant *get_root_property (GDBusConnection * connection,
    const char *sender,
    const char *object_path,
    const char *interface_name,
    const char *property_name, GError ** error, SnappyMP * mp);


G_END_DECLS
#endif /* __DLNA_H__ */
