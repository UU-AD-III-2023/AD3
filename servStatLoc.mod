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
# Cost of Placing Station at Zone Z (per vehicle)
param cost {i in Zones, j in Zones} := Time[j,i]/c * Demand[i];

# selected zone j for stations
var selectedZone {Zones}, binary;
# selected zone j to place budgetted service stations sending to zone i allocation[station, i, j]
var allocation {Zones, Zones} >=0, <=v;

# minimize the sum over all the zones of the average travel time of the c closest vehicles of each zone, multiplied by the demand of the zone.
minimize TotalCost: sum {i in Zones, j in Zones} allocation[i,j]*cost[i,j];

# Zone i totals to 3
subject to cLimit{i in Zones}: sum {j in Zones} allocation[i,j] = c;

# A station exists in only zone j and allocation to i Zone may vary
subject to selectedlimit{j in Zones, i in Zones}: allocation[i,j] <= selectedZone[j]*v;

# There exists only s Stations
subject to slimit: sum{j in Zones} selectedZone[j] = s;
