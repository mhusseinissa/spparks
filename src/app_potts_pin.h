/* ----------------------------------------------------------------------
   SPPARKS - Stochastic Parallel PARticle Kinetic Simulator
   http://www.cs.sandia.gov/~sjplimp/spparks.html
   Steve Plimpton, sjplimp@sandia.gov, Sandia National Laboratories

   Copyright (2008) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level SPPARKS directory.
------------------------------------------------------------------------- */

#ifndef APP_POTTS_PIN_H
#define APP_POTTS_PIN_H

#include "app_potts.h"

namespace SPPARKS_NS {

class AppPottsPin : public AppPotts {
 public:
  AppPottsPin(class SPPARKS *, int, char **);
  ~AppPottsPin() {}
  void input_app(char *, int, char **);

  void site_event_rejection(int, class RandomPark *);
  double site_propensity(int);
  void site_event(int, class RandomPark *);

 private:
  double pfraction;

  void pin_create();
};

}

#endif