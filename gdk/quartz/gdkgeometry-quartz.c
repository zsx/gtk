/* gdkgeometry-quartz.c
 *
 * Copyright (C) 2005 Imendio AB
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "config.h"

#include "gdkprivate-quartz.h"

void
_gdk_quartz_window_queue_translation (GdkWindow *window,
				      GdkGC     *gc,
                                      GdkRegion *area,
                                      gint       dx,
                                      gint       dy)
{
}

gboolean
_gdk_quartz_window_queue_antiexpose (GdkWindow *window,
                                     GdkRegion *area)
{
  return FALSE;
}
