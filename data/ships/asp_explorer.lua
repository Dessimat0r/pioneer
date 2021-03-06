-- Copyright © 2008-2012 Pioneer Developers. See AUTHORS.txt for details
-- Licensed under the terms of CC-BY-SA 3.0. See licenses/CC-BY-SA-3.0.txt

define_ship {
	name='Asp Explorer',
	model='asp_sparks',
	forward_thrust = -220e5,
	reverse_thrust = 100e5,
	up_thrust = 60e5,
	down_thrust = -60e5,
	left_thrust = -60e5,
	right_thrust = 60e5,
	angular_thrust = 600e5,
	cockpit_front = v(0,5,.5),
	cockpit_rear = v(0,7,9),
	front_camera = v(0,2,-17),
	rear_camera = v(0,1,24),
	left_camera = v(-23.5,1,8.5),
	right_camera = v(23.5,1,8.5),
	top_camera = v(0,6,5),
	bottom_camera = v(0,-5,5),
	gun_mounts =
	{
		{ v(0,2.57,-21.35), v(0,0,-1) },
		{ v(0,-4.42,26.04), v(0,0,1) },
	},
	max_cargo = 120,
	max_missile = 1,
	max_laser = 2,
	max_cargoscoop = 0,
	max_fuelscoop = 1,
	capacity = 120,
	hull_mass = 60,
	fuel_tank_mass = 40,
	thruster_fuel_use = 0.00014,
	price = 187000,
	hyperdrive_class = 3,
}
