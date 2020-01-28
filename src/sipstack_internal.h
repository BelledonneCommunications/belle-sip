/*
 * Copyright (c) 2012-2019 Belledonne Communications SARL.
 *
 * This file is part of belle-sip.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

 #ifndef SIPSTACK_INTERNAL_H_
 #define SIPSTACK_INTERNAL_H_

 /**
  * @brief Get the sip well_known_port.
  * @return The well_know port, 0 if not set.
  */

int belle_sip_get_well_known_port();

/**
 * @brief Set the sip well_known_port.
 * @param port
 */

void belle_sip_set_well_known_port(int port);

/**
 * @brief Get the sips well_known_port.
 * @return The well_know port, 0 if not set.
 */

int belle_sip_get_well_known_port_tls();

/**
* @brief Set the sips well_known_port.
* @param port
*/

void belle_sip_set_well_known_port_tls(int port);

#endif /* SIPSTACK_INTERNAL_H_ */
