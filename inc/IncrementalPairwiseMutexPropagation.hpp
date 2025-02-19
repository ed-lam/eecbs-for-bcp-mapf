#ifndef IPMP_H
#define IPMP_H

#include "eecbs/inc/MDD.h"
#include "eecbs/inc/SingleAgentSolver.h"

namespace eecbs
{

using namespace eecbs;

typedef std::vector <Constraint> con_vec;

class IPMutexPropagation{
private:
  MDD* MDD_0;
  MDD* MDD_1;
  int init_len_0;
  int init_len_1;
  int incr_limit;

  SingleAgentSolver* search_engine_0;
  SingleAgentSolver* search_engine_1;

  ConstraintTable cons_0;
  ConstraintTable cons_1;
public:
  IPMutexPropagation(MDD* MDD_0, MDD* MDD_1,
                     SingleAgentSolver* se_0, SingleAgentSolver* se_1,
                     ConstraintTable cons_0,
                     ConstraintTable cons_1,
                     int incr_limit = 20
                     );

  std::pair<con_vec, con_vec> gen_constraints();

  int final_len_0;
  int final_len_1;


};

}

#endif
