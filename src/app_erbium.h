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

#ifndef APP_ERBIUM_H
#define APP_ERBIUM_H

#include "app_lattice.h"

namespace SPPARKS_NS {

class AppErbium : public AppLattice {
 public:
  AppErbium(class SPPARKS *, int, char **);
  ~AppErbium();
  void init_app();

  double site_energy(int);
  void site_event_rejection(int, class RandomPark *);
  double site_propensity(int);
  void site_event(int, class RandomPark *);

 private:
  int *type,*element;      // variables on each lattice site

  int *sites;

  int nsingle,ndouble,ntriple;
  double *srate,*drate,*trate;
  double *spropensity,*dpropensity,*tpropensity;
  int *stype,**dtype,**ttype;
  int *sinput,**dinput,**tinput;
  int *soutput,**doutput,**toutput;

  struct Event {           // one event for an owned site
    int type;              // reaction type = 1,2,3 for single,double,triple
    int which;             // which reaction of this type
    int jpartner,kpartner; // which J,K neighbors of I are part of event
    int next;              // index of next event for this site
    double propensity;     // propensity of this event
  };

  Event *events;           // list of events for all owned sites
  int nevents;             // # of events for all owned sites
  int maxevent;            // max # of events list can hold
  int *firstevent;         // index of 1st event for each owned site
  int freeevent;           // index of 1st unused event in list

  void clear_events(int);
  void add_event(int, int, int, double, int, int);
};

}

#endif