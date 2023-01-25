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

# number selected from each zone j to zone i
var selectedC {Zones, Zones} >=0, <= s*v;

# minimize the sum over all the zones of the average travel time of the c closest vehicles of each zone, multiplied by the demand of the zone.
# Time[i,j] = Time[j,i]
minimize TotalTime: sum {i in Zones, j Zones} Time[i,j]*Demand[i]*selectedC[i,j]; # divide minimum by c*z at the end to get average

# Exactly c vehicles must be selected
subject to Limit {i in Zones}: sum {j in Zones} selectedC[i,j] = c;
