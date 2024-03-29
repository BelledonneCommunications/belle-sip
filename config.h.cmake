/***************************************************************************
* config.h.cmake
* Copyright (C) 2014  Belledonne Communications, Grenoble France
*
****************************************************************************
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
****************************************************************************/

#define BELLE_SIP_LOCAL_RESOURCE_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/tester"

#define SDP_LOCAL_GRAMMAR_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/src/sdp"

#cmakedefine PACKAGE "@PACKAGE@"
#cmakedefine PACKAGE_NAME "@PACKAGE_NAME@"
#cmakedefine PACKAGE_VERSION "@PACKAGE_VERSION@"
#cmakedefine PACKAGE_STRING "@PACKAGE_STRING@"
#cmakedefine PACKAGE_TARNAME "@PACKAGE_TARNAME@"
#cmakedefine PACKAGE_BUGREPORT "@PACKAGE_BUGREPORT@"
#cmakedefine PACKAGE_URL "@PACKAGE_URL@"
#cmakedefine VERSION "@VERSION@"

#cmakedefine HAVE_LIBDL
#cmakedefine HAVE_CLOCK_GETTIME

#cmakedefine HAVE_RESINIT

#cmakedefine HAVE_TUNNEL
#cmakedefine HAVE_ZLIB

#cmakedefine BELLE_SDP_FORCE_RTP_MAP
#cmakedefine ENABLE_SERVER_SOCKETS

#cmakedefine HAVE_MDNS
#cmakedefine HAVE_DNS_SERVICE
