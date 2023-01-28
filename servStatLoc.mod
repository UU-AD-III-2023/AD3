#
# Copyright: Pierre.Flener@it.uu.se and his teaching assistants, 2023.
#
# This file is part of course 1DL481 at Uppsala University, Sweden.
#
# Permission is hereby granted only to the registered students of that
# course to use this file, for a homework assignment.
#
# The copyright notice and permission notice above shall be included in
# all copies and extensions of this file, and those are not allowed to
# appear publicly on the internet, both during a course instance and
# forever after.
#

# Team: 7    # fill in our team number
# Authors: Anderson Leong Ke Sheng; Louis Henkel;

param z; # number of zones
param s; # number of service stations
param v; # number of vehicles per service station
param c; # number of closest vehicles for average
set Zones := 1..z;
param Demand {Zones} >= 0; # Demand[i] = demand of zone i
param Time {Zones,Zones} >= 0; # Time[i,j] = time from zone i to j

set Stations := 1..s;
set Vehicles := 1..v within Stations;

# Vehicles for Average
set Chosen := 1..c;

# Cost of Placing Station at Zone Z (per vehicle)
param cost {i in Zones, j in Zones} := Time[j,i] * Demand[i];

# selected zone to place budgetted service stations
var selectedZone {Zones, Stations} >=0, <= v, integer;

# minimize the sum over all the zones of the average travel time of the c closest vehicles of each zone, multiplied by the demand of the zone.
# minimize TimeSj {j in Zones}: sum {i in Zones, k in Stations, l in Vehicles} Time[j,i]*vSelectiontoZ[i,k,l]*Demand[i];
minimize TotalCost: sum {i in Zones, j in Zones, k in Stations} selectedZone[j,k]*cost[i,j];

subject to cLimit : sum {j in Zones, k in Stations} selectedZone[j,k] = c; # C stations
# subject to clim {i in Zones} : sum {k in Stations, l in Vehicles} vSelectiontoZ[i,k,l] = c; 
# subject to stationLimit : sum {j in Zones, k in Stations} selectedZone[j,i,k]-selectedZone[j,k] <= s*z; # C stations
# subject to serviceLimit {i in Zones}: sum {j in Zones} selectedZone[i,j] <= s*v; # maximum service station vehicles
