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


param p {Zones} >= 0; # p[i] = 1, if v cars in zone i are taken
param q {Zones} >= 0; # q[i] = 1, if c % v cars in zone i are taken
param r {Zones} >= 0; # r[i] = 1, if no cars from zone i are taken
param station_pos {Zones} >= 0; # station_pos[i] = 1, if station is in zone i

# limits on cars to take
subject to p:
  sum{z in Zones} (p[z]) = s / c;
subject to q:
  sum{z in Zones} (q[z]) = 1;
subject to r:
  sum{z in Zones} (r[z]) = z - s/c - 1;

subject to p, q: # p dot q = 0
  sum{z in Zones} (p[z] * q[z]) = 0
subject to p, r: # p dot r = 0
  sum{z in Zones} (p[z] * r[z]) = 0
subject to q, r: # q dot r = 0
  sum{z in Zones} (q[z] * r[z]) = 0
subject to p, station_pos:
  sum{z in Zones} (p[z] * s[z]) = s / c

## add minimize distance.




# selected zone to place budgetted service stations
var selectedZone {Zones} >=0, <= s*v, integer;

# minimize the sum over all the zones of the average travel time of the c closest vehicles of each zone, multiplied by the demand of the zone.
# Time from j to i * demand of i * number of stations from j to i
minimize TotalTime: sum {i in Zones, j in Zones} Time[j,i]*Demand[i]*selectedZone[j];

subject to stationLimit : sum {i in Zones} selectedZone[i] = c; # C stations
# subject to serviceLimit {i in Zones}: sum {j in Zones} selectedZone[i,j] <= s*v; # maximum service station vehicles
