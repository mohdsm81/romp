/*
	Generated code for a romp "parallel random walker" verification tool based off of the Murphi Model described in:
		Original Murphi Model: n_peterson.hard-bug.m
	Please build with the following command(s):
		<not-implemented-yet>
*/


#define __romp__GENERATED_CODE


#define _ROMP_STATE_TYPE ::__model__::__Model__


#define _ROMP_STATE_HISTORY_LEN (4ul)


#define _ROMP_THREAD_TO_RW_RATIO (8ul)


#define __model__filepath "/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m"


#define __model__filepath_contains_space (true)


#define __model__filename "n_peterson.hard-bug.m"

#define __model__filename_contains_space (false)


#define __romp__ENABLE_assume_property

#define __romp__ENABLE_cover_property

#define __romp__ENABLE_liveness_property

#define __romp__ENABLE_symmetry

#pragma region inline_library_includes


#pragma endregion inline_library_includes

namespace __model__ { struct __Model__; } // helpful pre-definition


#pragma region model_prefixes

#include "/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/resources/c_prefix.cpp"

#pragma endregion model_prefixes



#pragma region generated_code


/* ======= Header Comments ====== */


/* ======= Model Type & Const Definitions ====== */

namespace __type__ {
  typedef int range_t;
  typedef unsigned int scalarset_t;
  typedef int enum_backend_t;
  const __typeof__(((int)(32))) TBL = ((int)(32));
  const __typeof__(((int)(4))) N = ((int)(4)); // the number of processes
  const __typeof__(((N) * ((int)(2)))) BL = ((N) * ((int)(2))); // the used size of the "bug array" (must never be bigger than TBL) 
  const __typeof__(((int)(2))) MSL = ((int)(2));
  typedef scalarset_t pid;
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& pid_to_json(::romp::ojstream<O>& json, const pid& val) noexcept { json << val; return ::romp::S_VOID; }
#else
  template<class O> const ::romp::stream_void& pid_to_json(::romp::ojstream<O>& json, const pid& val) noexcept { json << "{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"bound\":4,\"value\":" << ((scalarset_t)val) << "}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& pid_to_str(::romp::ostream_p& out, const pid& val) noexcept { out << ((scalarset_t)val); return ::romp::S_VOID;}

  typedef range_t pid_r; // math workable range version of pid
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& pid_r_to_json(::romp::ojstream<O>& json, const pid_r& val) noexcept { json << val; return ::romp::S_VOID; }
#else
  template<class O> const ::romp::stream_void& pid_r_to_json(::romp::ojstream<O>& json, const pid_r& val) noexcept { json << "{\"$type\":\"range-value\",\"type\":\"pid_r\",\"min\":" << (VALUE_C(0)) << ",\"max\":" << (VALUE_C(3)) << ",\"value\":" << ((range_t)val) << "}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& pid_r_to_str(::romp::ostream_p& out, const pid_r& val) noexcept { out << ((range_t)val); return ::romp::S_VOID;}

  typedef range_t bug_r; // math workable version of bug lengthl
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& bug_r_to_json(::romp::ojstream<O>& json, const bug_r& val) noexcept { json << val; return ::romp::S_VOID; }
#else
  template<class O> const ::romp::stream_void& bug_r_to_json(::romp::ojstream<O>& json, const bug_r& val) noexcept { json << "{\"$type\":\"range-value\",\"type\":\"bug_r\",\"min\":" << (VALUE_C(0)) << ",\"max\":" << (VALUE_C(7)) << ",\"value\":" << ((range_t)val) << "}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& bug_r_to_str(::romp::ostream_p& out, const bug_r& val) noexcept { out << ((range_t)val); return ::romp::S_VOID;}

  typedef range_t priority;
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& priority_to_json(::romp::ojstream<O>& json, const priority& val) noexcept { json << val; return ::romp::S_VOID; }
#else
  template<class O> const ::romp::stream_void& priority_to_json(::romp::ojstream<O>& json, const priority& val) noexcept { json << "{\"$type\":\"range-value\",\"type\":\"priority\",\"min\":" << (VALUE_C(0)) << ",\"max\":" << (VALUE_C(4)) << ",\"value\":" << ((range_t)val) << "}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& priority_to_str(::romp::ostream_p& out, const priority& val) noexcept { out << ((range_t)val); return ::romp::S_VOID;}

  typedef enum { L0, L1, L2, L3, L4, } label_t;
  std::string to_string(const label_t val) { switch (val) { case L0: return "L0"; case L1: return "L1"; case L2: return "L2"; case L3: return "L3"; case L4: return "L4"; default: break; } return "label_t::__UNKNOWN_ENUM_VALUE__"; }
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& label_t_to_json(::romp::ojstream<O>& json, const label_t& val) noexcept { json << '"' << to_string(val) << '"'; return ::romp::S_VOID; }
#else
  template<class O> const ::romp::stream_void& label_t_to_json(::romp::ojstream<O>& json, const label_t& val) noexcept { json << "{\"$type\":\"enum-value\",\"type\":\"label_t\",\"value\":\"" << to_string(val) <<"\"}"; return ::romp::S_VOID; }
#endif
  const ::romp::stream_void& label_t_to_str(::romp::ostream_p& out, const label_t& val) noexcept { out << to_string(val); return ::romp::S_VOID; }

  typedef struct { ::__type__::label_t data[4]; size_t size() const {return (4ul);} } anon0x0_t; // stores the current state of each process
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& anon0x0_t_to_json(::romp::ojstream<O>& json, const anon0x0_t& val) noexcept {std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << label_t_to_json(json,val.data[i]); sep = ","; } return ::romp::S_VOID;}
#else
  template<class O> const ::romp::stream_void& anon0x0_t_to_json(::romp::ojstream<O>& json, const anon0x0_t& val) noexcept {json << "{\"$type\":\"array-value\",\"type\":\"Array[pid] of label_t\",\"size\":" << val.size() << ",\"lower-bound\":" << VALUE_C(0) << ",\"upper-bound\":" << VALUE_C(3) << ",\"elements\":["; std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << label_t_to_json(json,val.data[i]); sep = ","; } json << "]}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& anon0x0_t_to_str(::romp::ostream_p& out, const anon0x0_t& val) noexcept { out << "[\n" << out.indent(); for (size_t i=0; i<val.size(); ++i) { out << out.indentation() << "[" << (i + (VALUE_C(0))) << "]: "<< label_t_to_str(out,val.data[i]) << '\n'; } out << out.dedent() << out.indentation() << ']'; return ::romp::S_VOID;}

  typedef struct { ::__type__::priority data[4]; size_t size() const {return (4ul);} } anon0x1_t; // stores what priority each process has
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& anon0x1_t_to_json(::romp::ojstream<O>& json, const anon0x1_t& val) noexcept {std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << priority_to_json(json,val.data[i]); sep = ","; } return ::romp::S_VOID;}
#else
  template<class O> const ::romp::stream_void& anon0x1_t_to_json(::romp::ojstream<O>& json, const anon0x1_t& val) noexcept {json << "{\"$type\":\"array-value\",\"type\":\"Array[pid] of priority\",\"size\":" << val.size() << ",\"lower-bound\":" << VALUE_C(0) << ",\"upper-bound\":" << VALUE_C(3) << ",\"elements\":["; std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << priority_to_json(json,val.data[i]); sep = ","; } json << "]}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& anon0x1_t_to_str(::romp::ostream_p& out, const anon0x1_t& val) noexcept { out << "[\n" << out.indent(); for (size_t i=0; i<val.size(); ++i) { out << out.indentation() << "[" << (i + (VALUE_C(0))) << "]: "<< priority_to_str(out,val.data[i]) << '\n'; } out << out.dedent() << out.indentation() << ']'; return ::romp::S_VOID;}

  typedef struct { ::__type__::pid data[5]; size_t size() const {return (5ul);} } anon0x2_t; // maps each priority to a process
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& anon0x2_t_to_json(::romp::ojstream<O>& json, const anon0x2_t& val) noexcept {std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << pid_to_json(json,val.data[i]); sep = ","; } return ::romp::S_VOID;}
#else
  template<class O> const ::romp::stream_void& anon0x2_t_to_json(::romp::ojstream<O>& json, const anon0x2_t& val) noexcept {json << "{\"$type\":\"array-value\",\"type\":\"Array[priority] of pid\",\"size\":" << val.size() << ",\"lower-bound\":" << VALUE_C(0) << ",\"upper-bound\":" << VALUE_C(4) << ",\"elements\":["; std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << pid_to_json(json,val.data[i]); sep = ","; } json << "]}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& anon0x2_t_to_str(::romp::ostream_p& out, const anon0x2_t& val) noexcept { out << "[\n" << out.indent(); for (size_t i=0; i<val.size(); ++i) { out << out.indentation() << "[" << (i + (VALUE_C(0))) << "]: "<< pid_to_str(out,val.data[i]) << '\n'; } out << out.dedent() << out.indentation() << ']'; return ::romp::S_VOID;}

  typedef struct { ::__type__::priority data[4]; size_t size() const {return (4ul);} } anon0x3_t; // maps each process to it's current priority
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& anon0x3_t_to_json(::romp::ojstream<O>& json, const anon0x3_t& val) noexcept {std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << priority_to_json(json,val.data[i]); sep = ","; } return ::romp::S_VOID;}
#else
  template<class O> const ::romp::stream_void& anon0x3_t_to_json(::romp::ojstream<O>& json, const anon0x3_t& val) noexcept {json << "{\"$type\":\"array-value\",\"type\":\"Array[pid] of priority\",\"size\":" << val.size() << ",\"lower-bound\":" << VALUE_C(0) << ",\"upper-bound\":" << VALUE_C(3) << ",\"elements\":["; std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << priority_to_json(json,val.data[i]); sep = ","; } json << "]}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& anon0x3_t_to_str(::romp::ostream_p& out, const anon0x3_t& val) noexcept { out << "[\n" << out.indent(); for (size_t i=0; i<val.size(); ++i) { out << out.indentation() << "[" << (i + (VALUE_C(0))) << "]: "<< priority_to_str(out,val.data[i]) << '\n'; } out << out.dedent() << out.indentation() << ']'; return ::romp::S_VOID;}

  typedef struct { ::__type__::pid data[4]; size_t size() const {return (4ul);} } anon0x4_t;
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& anon0x4_t_to_json(::romp::ojstream<O>& json, const anon0x4_t& val) noexcept {std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << pid_to_json(json,val.data[i]); sep = ","; } return ::romp::S_VOID;}
#else
  template<class O> const ::romp::stream_void& anon0x4_t_to_json(::romp::ojstream<O>& json, const anon0x4_t& val) noexcept {json << "{\"$type\":\"array-value\",\"type\":\"Array[pid_r] of pid\",\"size\":" << val.size() << ",\"lower-bound\":" << VALUE_C(0) << ",\"upper-bound\":" << VALUE_C(3) << ",\"elements\":["; std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << pid_to_json(json,val.data[i]); sep = ","; } json << "]}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& anon0x4_t_to_str(::romp::ostream_p& out, const anon0x4_t& val) noexcept { out << "[\n" << out.indent(); for (size_t i=0; i<val.size(); ++i) { out << out.indentation() << "[" << (i + (VALUE_C(0))) << "]: "<< pid_to_str(out,val.data[i]) << '\n'; } out << out.dedent() << out.indentation() << ']'; return ::romp::S_VOID;}

  typedef range_t m_int;
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& m_int_to_json(::romp::ojstream<O>& json, const m_int& val) noexcept { json << val; return ::romp::S_VOID; }
#else
  template<class O> const ::romp::stream_void& m_int_to_json(::romp::ojstream<O>& json, const m_int& val) noexcept { json << "{\"$type\":\"range-value\",\"type\":\"__UNKNOWN_TYPE_REPR__\",\"min\":" << (VALUE_C(-2147483647)) << ",\"max\":" << (VALUE_C(2147483647)) << ",\"value\":" << ((range_t)val) << "}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& m_int_to_str(::romp::ostream_p& out, const m_int& val) noexcept { out << ((range_t)val); return ::romp::S_VOID;}

  typedef struct { ::__type__::pid data[4]; size_t size() const {return (4ul);} } anon0x5_t;
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> const ::romp::stream_void& anon0x5_t_to_json(::romp::ojstream<O>& json, const anon0x5_t& val) noexcept {std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << pid_to_json(json,val.data[i]); sep = ","; } return ::romp::S_VOID;}
#else
  template<class O> const ::romp::stream_void& anon0x5_t_to_json(::romp::ojstream<O>& json, const anon0x5_t& val) noexcept {json << "{\"$type\":\"array-value\",\"type\":\"Array[pid_r] of pid\",\"size\":" << val.size() << ",\"lower-bound\":" << VALUE_C(0) << ",\"upper-bound\":" << VALUE_C(3) << ",\"elements\":["; std::string sep; for (size_t i=(0ul); i<val.size(); ++i) { json << sep << pid_to_json(json,val.data[i]); sep = ","; } json << "]}"; return ::romp::S_VOID;}
#endif
  const ::romp::stream_void& anon0x5_t_to_str(::romp::ostream_p& out, const anon0x5_t& val) noexcept { out << "[\n" << out.indent(); for (size_t i=0; i<val.size(); ++i) { out << out.indentation() << "[" << (i + (VALUE_C(0))) << "]: "<< pid_to_str(out,val.data[i]) << '\n'; } out << out.dedent() << out.indentation() << ']'; return ::romp::S_VOID;}


}



/* ======= Generated Model & State ====== */

namespace __model__ {

  struct __Model__ {
    ::romp::IRandWalker* __rw__; // reference to associated romp rand walker


    /* ======= Model State Variables ====== */

    ::__type__::anon0x0_t P;

    ::__type__::anon0x1_t Q;

    ::__type__::anon0x2_t turn;

    ::__type__::anon0x3_t localj;

    ::__type__::anon0x4_t lock_hist;

    ::__type__::pid_r lh_size; // start and end of circ buffer

    ::__type__::boolean lh_is_full; // if we circling yet (aka need to move start/lh_i forward)


    /* ======= Murphi Model Functions ====== */

    
    ::__type__::pid bug(const ::__type__::bug_r i) const  {
      using namespace ::__type__;
      try {
        //------------------------------------------------------------------------
        // Copyright (C) 1992 by the Board of Trustees of 			  
        // Leland Stanford Junior University.					  
        //									  
        // This description is provided to serve as an example of the use	  
        // of the Murphi description language and verifier, and as a benchmark	  
        // example for other verification efforts.				  
        //									  
        // License to use, copy, modify, sell and/or distribute this description  
        // and its documentation any purpose is hereby granted without royalty,   
        // subject to the following terms and conditions, provided		  
        //									  
        // 1.  The above copyright notice and this permission notice must	  
        // appear in all copies of this description.				  
        // 									  
        // 2.  The Murphi group at Stanford University must be acknowledged	  
        // in any publication describing work that makes use of this example. 	  
        // 									  
        // Nobody vouches for the accuracy or usefulness of this description	  
        // for any purpose.							  
        //------------------------------------------------------------------------
        //------------------------------------------------------------------------
        // NOTE: This model with a "bug" inserted into it, 
        //        might not compile with CMurphi 
        //        or traditional/old/original Murphi
        //       This is because the getRand function relies 
        //        on bitwise AND, OR & NOT, which og spec does not have.
        //       It is designed to work with the parser and AST from the rumur-lib 
        //------------------------------------------------------------------------
        //------------------------------------------------------------------------
        //
        //                                                                        
        // File:        muxn.m                                                    
        //                                                                        
        // Content:     Peterson's algorithm (mutual exclusion for n-processes)   
        //                                                                        
        // Summary of result:                                                     
        //          1)  No bug is discovered 					  
        //          2)  Details of result can be found at the end of this file.   
        //                                                                        
        // References: 						       	       	  
        // Peterson, G.L.,  Myths about the mutual exclusion problem,             
        // Information processing letters, Vol 12, No 3, 1981.                    
        //                                                                        
        // Date created:         28 Oct 92                                        
        // Last Modified:        17 Feb 93                                        
        //                                                                        
        //------------------------------------------------------------------------
        //------------------------------------------------------------------------
        // Alternate bug inserted here:
        //   Bug checks if the order of locks ever contains a subsequence of 
        //    a predefined "buggy" ordering & if it does it breaks an invariant  
        //------------------------------------------------------------------------
        // the number of processes
        // the used size of the "bug array" (must never be bigger than TBL) 
        //  The scalarset is used for symmetry, which is implemented in Murphi 1.5
        //  and not upgraded to Murphi 2.0 yet
        // pid: 1..N;
        // : non critical section; j := 1; while j<n do
        // : Beginwhile Q[i] := j  
        // : turn[j] := i   (asking the other process to take turn / update the turn system)
        // : wait until (forall k != i, Q[k] < j) or turn[j] != i ; j++; Endwhile  (wait for your turn) <-- you get lock here
        // : critical section; Q[i] := 0  (your turn)
        // locking history buffer
        // any process at L3 can do this but only 
        // if all other process has a lower/worse priority
        //forall
        // ?!? if our current processes priority is not associated with our process ?!?
        // ?!?  |-> this probs means if it is not our turn (this exists to keep the always action below from executing past range bounds)
        // always increase local priority (i.e the for loop from wikipedia)
        // go update the Q again
        // when localj[i] = N -> it is now our turn 
        // this assigns the lock to (us)
        //If 
        //If
        // we have fully reached the lock (update history)
        //Ruleset
        //For
        //For
        // hist bug stuff
        // critical
        // critical
        //Exists
        //Exists
        ::__type__::anon0x5_t pids;
        ::__type__::m_int tmp;
        ::__type__::m_int fact;
        ::__type__::m_int sum;
        // build a hacky map from range to scalarset
        do {
          for (int p = 0; p < (N); p++) {
            do {
              for (int pi = (p); pi <= (p); pi += 1) {
                ((pids).data[((pi)) - int_VALUE_C(0)]) = (p);
              }
            } while (0);
          }
        } while (0);
        // factorial & sum
        (fact) = (i);
        (sum) = (i);
        do {
          for (int j = ((i) - ((int)(1))); j <= ((int)(1)); j += 1) {
            (fact) = ((fact) * (j));
            (sum) = ((sum) + (j));
          }
        } while (0);
        return ((pids).data[((((fact) - (sum)) % (N))) - int_VALUE_C(0)]);
      } catch (...) { throw ::romp::ModelFunctError(0); }
}


    /* ======= Murphi Model StartStates, Rules & Global Properties ====== */

     void __StartState__init(void){
      using namespace ::__type__;
      try {
        do {
          for (int i = 0; i < (N); i++) {
            ((P).data[((i)) - int_VALUE_C(0)]) = (L0);
            ((Q).data[((i)) - int_VALUE_C(0)]) = ((int)(0));
          }
        } while (0);
        do {
          for (int i = ((int)(0)); i <= (N); i++) {
            memset(&((turn).data[((i)) - int_VALUE_C(0)]), 0, sizeof(((turn).data[((i)) - int_VALUE_C(0)])));
          }
        } while (0);
        memset(&(localj), 0, sizeof((localj)));
        (lh_is_full) = (false);
        (lh_size) = ((int)(0));
        memset(&(lock_hist), 0, sizeof((lock_hist)));
        if ((BL) > (TBL)) {
          if (this->__rw__->error_handler(0u))
            throw ::romp::ModelMErrorError(0);

        }
        if ((MSL) < ((int)(2))) {
          if (this->__rw__->error_handler(1u))
            throw ::romp::ModelMErrorError(1);

        }
      } catch (...) { throw ::romp::ModelStartStateError(0); }
    }



    
    bool __Rule_guard__L0_execute_inc_j_and_while(const ::__type__::pid i) const {
      using namespace ::__type__;
      try {
        return (((P).data[((i)) - int_VALUE_C(0)]) == (L0));
      } catch (...) { throw ::romp::ModelRuleError(0,::romp::ModelRuleError::GUARD); }
    }

    
    void __Rule_action__L0_execute_inc_j_and_while(const ::__type__::pid i) {
      using namespace ::__type__;
      try {
        ((localj).data[((i)) - int_VALUE_C(0)]) = ((int)(1));
        ((P).data[((i)) - int_VALUE_C(0)]) = (L1);
      } catch (...) { throw ::romp::ModelRuleError(0,::romp::ModelRuleError::ACTION); }
    }

    
    bool __Rule_guard__L1_execute_assign_Qi_j(const ::__type__::pid i) const {
      using namespace ::__type__;
      try {
        return (((P).data[((i)) - int_VALUE_C(0)]) == (L1));
      } catch (...) { throw ::romp::ModelRuleError(1,::romp::ModelRuleError::GUARD); }
    }

    
    void __Rule_action__L1_execute_assign_Qi_j(const ::__type__::pid i) {
      using namespace ::__type__;
      try {
        ((Q).data[((i)) - int_VALUE_C(0)]) = ((localj).data[((i)) - int_VALUE_C(0)]);
        ((P).data[((i)) - int_VALUE_C(0)]) = (L2);
      } catch (...) { throw ::romp::ModelRuleError(1,::romp::ModelRuleError::ACTION); }
    }

    
    bool __Rule_guard__L2_execute_assign_TURNj_i(const ::__type__::pid i) const {
      using namespace ::__type__;
      try {
        return (((P).data[((i)) - int_VALUE_C(0)]) == (L2));
      } catch (...) { throw ::romp::ModelRuleError(2,::romp::ModelRuleError::GUARD); }
    }

    
    void __Rule_action__L2_execute_assign_TURNj_i(const ::__type__::pid i) {
      using namespace ::__type__;
      try {
        ((turn).data[(((localj).data[((i)) - int_VALUE_C(0)])) - int_VALUE_C(0)]) = (i);
        ((P).data[((i)) - int_VALUE_C(0)]) = (L3);
      } catch (...) { throw ::romp::ModelRuleError(2,::romp::ModelRuleError::ACTION); }
    }

    
    bool __Rule_guard__L3_execute_wait_until(const ::__type__::pid i) const {
      using namespace ::__type__;
      try {
        return (((P).data[((i)) - int_VALUE_C(0)]) == (L3));
      } catch (...) { throw ::romp::ModelRuleError(3,::romp::ModelRuleError::GUARD); }
    }

    
    void __Rule_action__L3_execute_wait_until(const ::__type__::pid i) {
      using namespace ::__type__;
      try {
        if (({ bool res_0 = true; for (int k = 0; k < (N); k++) { res_0&= (!((k) != (i)) || (((Q).data[((k)) - int_VALUE_C(0)]) < ((localj).data[((i)) - int_VALUE_C(0)]))); } res_0; }) || (((turn).data[(((localj).data[((i)) - int_VALUE_C(0)])) - int_VALUE_C(0)]) != (i))) {
          ((localj).data[((i)) - int_VALUE_C(0)]) = (((localj).data[((i)) - int_VALUE_C(0)]) + ((int)(1)));
          if (((localj).data[((i)) - int_VALUE_C(0)]) < (N)) {
            ((P).data[((i)) - int_VALUE_C(0)]) = (L1);
          } else {
            ((P).data[((i)) - int_VALUE_C(0)]) = (L4);
          }
        }
      } catch (...) { throw ::romp::ModelRuleError(3,::romp::ModelRuleError::ACTION); }
    }

    
    bool __Rule_guard__L4_execute_critical_and_assign_Qi_1(const ::__type__::pid i) const {
      using namespace ::__type__;
      try {
        return (((P).data[((i)) - int_VALUE_C(0)]) == (L4));
      } catch (...) { throw ::romp::ModelRuleError(4,::romp::ModelRuleError::GUARD); }
    }

    
    void __Rule_action__L4_execute_critical_and_assign_Qi_1(const ::__type__::pid i) {
      using namespace ::__type__;
      try {
        ((Q).data[((i)) - int_VALUE_C(0)]) = ((int)(1));
        ((P).data[((i)) - int_VALUE_C(0)]) = (L0);
        ((lock_hist).data[((lh_size)) - int_VALUE_C(0)]) = (i);
        (lh_size) = (((lh_size) + ((int)(1))) % (N));
        (lh_is_full) = ((lh_size) == ((int)(0)));
      } catch (...) { throw ::romp::ModelRuleError(4,::romp::ModelRuleError::ACTION); }
    }


    
    bool __Property__only_one_P_has_lock(void) const {
      using namespace ::__type__;
      try {
        return this->__rw__->invariant_handler((!({ bool res_1 = false; for (int i1 = 0; i1 < (N); i1++) { res_1 |= ({ bool res_2 = false; for (int i2 = 0; i2 < (N); i2++) { res_2 |= ((((i1) != (i2)) && (((P).data[((i1)) - int_VALUE_C(0)]) == (L4))) && (((P).data[((i2)) - int_VALUE_C(0)]) == (L4))); } res_2; }); } res_1; })),0u);
      } catch (...) { throw ::romp::ModelPropertyError(0); }
    }

    
    bool __Property__injected_hist_subseq_bug(void) const {
      using namespace ::__type__;
      try {
        return this->__rw__->invariant_handler(((!(lh_is_full)) || (!({ bool res_3 = false; for (int l = (MSL); l <= (N); l++) { res_3 |= ({ bool res_4 = false; for (int b_i = ((int)(0)); b_i <= ((BL) - (l)); b_i += 1) { res_4 |= ({ bool res_5 = false; for (int lh_i = ((int)(0)); lh_i <= ((N) - (l)); lh_i += 1) { res_5 |= ({ bool res_6 = true; for (int j = ((int)(0)); j <= ((l) - ((int)(1))); j += 1) { res_6&= (::__model__::__Model__::bug(((b_i) + (j))) == ((lock_hist).data[(((lh_i) + (j))) - int_VALUE_C(0)])); } res_6; }); } res_5; }); } res_4; }); } res_3; }))),1u);
      } catch (...) { throw ::romp::ModelPropertyError(1); }
    }


  };

  /* ======= Murphi Model Output Functions ====== */
#ifdef __ROMP__SIMPLE_TRACE
template<class O> const ::romp::stream_void& __Model___to_json(::romp::ojstream<O>& json, const __Model__& val) noexcept { using namespace ::__type__; json  << anon0x0_t_to_json(json,val.P) << ',' << anon0x1_t_to_json(json,val.Q) << ',' << anon0x2_t_to_json(json,val.turn) << ',' << anon0x3_t_to_json(json,val.localj) << ',' << anon0x4_t_to_json(json,val.lock_hist) << ',' << pid_r_to_json(json,val.lh_size) << ',' << boolean_to_json(json,val.lh_is_full); return ::romp::S_VOID; }
#else
template<class O> const ::romp::stream_void& __Model___to_json(::romp::ojstream<O>& json, const __Model__& val) noexcept { using namespace ::__type__; json << "{\"$type\":\"record-value\",\"type\":\"__Model__\",\"fields\":[" << "{\"$type\":\"kv-pair\",\"key\":\"P\",\"value\":" << anon0x0_t_to_json(json,val.P) << "}," << "{\"$type\":\"kv-pair\",\"key\":\"Q\",\"value\":" << anon0x1_t_to_json(json,val.Q) << "}," << "{\"$type\":\"kv-pair\",\"key\":\"turn\",\"value\":" << anon0x2_t_to_json(json,val.turn) << "}," << "{\"$type\":\"kv-pair\",\"key\":\"localj\",\"value\":" << anon0x3_t_to_json(json,val.localj) << "}," << "{\"$type\":\"kv-pair\",\"key\":\"lock_hist\",\"value\":" << anon0x4_t_to_json(json,val.lock_hist) << "}," << "{\"$type\":\"kv-pair\",\"key\":\"lh_size\",\"value\":" << pid_r_to_json(json,val.lh_size) << "}," << "{\"$type\":\"kv-pair\",\"key\":\"lh_is_full\",\"value\":" << boolean_to_json(json,val.lh_is_full)<< "}]}"; return ::romp::S_VOID;}
#endif
const ::romp::stream_void& __Model___to_str(::romp::ostream_p& out, const __Model__& val) noexcept { using namespace ::__type__; out << "{\n" << out.indent() << out.indentation() << "P " << ((::romp::OPTIONS.result_show_type) ? ": Array[pid] of label_t =" : ":=") << ' ' << anon0x0_t_to_str(out,val.P) << '\n' << out.indentation() << "Q " << ((::romp::OPTIONS.result_show_type) ? ": Array[pid] of priority =" : ":=") << ' ' << anon0x1_t_to_str(out,val.Q) << '\n' << out.indentation() << "turn " << ((::romp::OPTIONS.result_show_type) ? ": Array[priority] of pid =" : ":=") << ' ' << anon0x2_t_to_str(out,val.turn) << '\n' << out.indentation() << "localj " << ((::romp::OPTIONS.result_show_type) ? ": Array[pid] of priority =" : ":=") << ' ' << anon0x3_t_to_str(out,val.localj) << '\n' << out.indentation() << "lock_hist " << ((::romp::OPTIONS.result_show_type) ? ": Array[pid_r] of pid =" : ":=") << ' ' << anon0x4_t_to_str(out,val.lock_hist) << '\n' << out.indentation() << "lh_size " << ((::romp::OPTIONS.result_show_type) ? ": pid_r =" : ":=") << ' ' << pid_r_to_str(out,val.lh_size) << '\n' << out.indentation() << "lh_is_full " << ((::romp::OPTIONS.result_show_type) ? ": __Model__ =" : ":=") << ' ' << boolean_to_str(out,val.lh_is_full) << '\n' << out.dedent()<< out.indentation() << '}'; return ::romp::S_VOID;}
}
namespace romp {
#ifdef __ROMP__SIMPLE_TRACE
  template<class O> ::romp::ojstream<O>& operator << (::romp::ojstream<O>& json, const ::__model__::__Model__& s) { json << '[' << ::__model__::__Model___to_json(json,s) << ']'; return json; }
#else
  template<class O> ::romp::ojstream<O>& operator << (::romp::ojstream<O>& json, const ::__model__::__Model__& s) { (void) ::__model__::__Model___to_json(json,s); return json; }
#endif
  ::romp::ostream_p& operator << (::romp::ostream_p& out, const ::__model__::__Model__& s) { (void) ::__model__::__Model___to_str(out,s); return out; }
  ::std::ostream& operator << (::std::ostream& out_, const ::__model__::__Model__& s) { ::romp::ostream_p out(out_,2); (void) ::__model__::__Model___to_str(out,s); return out_; }
}



/* ======= Murphi Model Infos & MetaData ====== */
namespace __info__ {

/* the number possible variations in the state (# of permutations of the state-space) */
#define _ROMP_STATESPACE_COUNT_str "344373768000000000000"
/* the number of functions & procedures in the model */
#define _ROMP_FUNCTS_LEN (1ul)
  /* the info/metadata about the functions/procedures in the model */
  const ::romp::FunctInfo FUNCT_INFOS[_ROMP_FUNCTS_LEN] = {{"bug",{{185,1},{199,5}},"{\"$type\":\"function\",\"return-type\":\"pid\",\"label\":\"bug\",\"params\":[{\"$type\":\"param\",\"id\":\"i\",\"type\":\"bug_r\"}],\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[185,1],\"end\":[199,5]}}","function bug(var i: bug_r) : pid;"},};
/* the number of error statements in the model */
#define _ROMP_ERRORS_LEN (2ul)
  /* the info/metadata about the murphi error statements in the model */
  const ::romp::MErrorInfo ERROR_INFOS[_ROMP_ERRORS_LEN] = {{"CONFIG ERROR: `BL` needs to <= `TBL` !!\\032",{{167,10},{167,61}},0,"{\"$type\":\"error-statement\",\"label\":\"CONFIG ERROR: `BL` needs to <= `TBL` !!\\\\032\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[167,10],\"end\":[167,61]}"},{"CONFIG ERROR: `MSL` needs to at least 2 to be a proper subseq !!",{{170,10},{170,82}},0,"{\"$type\":\"error-statement\",\"label\":\"CONFIG ERROR: `MSL` needs to at least 2 to be a proper subseq !!\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[170,10],\"end\":[170,82]}"},};
/* the number of property statements & rules in the model */
#define _ROMP_PROPERTIES_LEN (2ul)
/* the number of cover property statements & rules in the model */
#define _ROMP_COVER_PROP_COUNT (0ul) // the number of property rules (after ruleset expansion) in the model
/* the number of liveness property rules in the model */
#define _ROMP_LIVENESS_PROP_COUNT (0ul) // the number of property rules (after ruleset expansion) in the model
  /* the info/metadata about the murphi properties in the model */
  const ::romp::PropertyInfo PROPERTY_INFOS[_ROMP_PROPERTIES_LEN] = {{"only_one_P_has_lock",::romp::PropertyType::INVARIANT,"(!exists i1 : pid do exists i2 : pid do (((i1 != i2) & (P[i1] = L4)) & (P[i2] = L4)) endexists endexists)",0,{{174,1},{182,8}},"{\"$type\":\"property\",\"type\":\"invariant\",\"expr\":\"(!exists i1 : pid do exists i2 : pid do (((i1 != i2) & (P[i1] = L4)) & (P[i2] = L4)) endexists endexists)\",\"label\":\"only_one_P_has_lock\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[174,1],\"end\":[182,8]}"},{"injected_hist_subseq_bug",::romp::PropertyType::INVARIANT,"((!lh_is_full) | (!exists l : MSL..N do exists b_i from 0 to (BL - l) do exists lh_i from 0 to (N - l) do forall j from 0 to (l - 1) do (bug((b_i + j)) = lock_hist[(lh_i + j)]) endforall endexists endexists endexists))",1,{{201,1},{211,18}},"{\"$type\":\"property\",\"type\":\"invariant\",\"expr\":\"((!lh_is_full) | (!exists l : MSL..N do exists b_i from 0 to (BL - l) do exists lh_i from 0 to (N - l) do forall j from 0 to (l - 1) do (bug((b_i + j)) = lock_hist[(lh_i + j)]) endforall endexists endexists endexists))\",\"label\":\"injected_hist_subseq_bug\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[201,1],\"end\":[211,18]}"},};
/* the number of start state rules (before ruleset expansions) in the model */
#define _ROMP_STARTSTATE_INFO_LEN (1ul)
  /* the info/metadata about the startstate rules in the model */
  const ::romp::StartStateInfo STARTSTATE_INFOS[_ROMP_STARTSTATE_INFO_LEN] = {{"init",{{149,1},{172,4}},"{\"$type\":\"startstate\",\"label\":\"init\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[149,1],\"end\":[172,4]}"},};
/* the number of rules in the model, BEFORE ruleset expansion */
#define _ROMP_RULESETS_LEN (5ul)
  /* the info/metadata about the rules in the model */
  const ::romp::RuleInfo RULE_SET_INFOS[_ROMP_RULESETS_LEN] = {{"L0_execute_inc_j_and_while",{{95,3},{100,6}},"{\"$type\":\"rule\",\"expr\":\"(P[i] = L0)\",\"label\":\"L0_execute_inc_j_and_while\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[95,3],\"end\":[100,6]}"},{"L1_execute_assign_Qi_j",{{102,3},{107,6}},"{\"$type\":\"rule\",\"expr\":\"(P[i] = L1)\",\"label\":\"L1_execute_assign_Qi_j\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[102,3],\"end\":[107,6]}"},{"L2_execute_assign_TURNj_i",{{109,3},{114,6}},"{\"$type\":\"rule\",\"expr\":\"(P[i] = L2)\",\"label\":\"L2_execute_assign_TURNj_i\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[109,3],\"end\":[114,6]}"},{"L3_execute_wait_until",{{116,3},{132,6}},"{\"$type\":\"rule\",\"expr\":\"(P[i] = L3)\",\"label\":\"L3_execute_wait_until\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[116,3],\"end\":[132,6]}"},{"L4_execute_critical_and_assign_Qi_1",{{134,3},{143,6}},"{\"$type\":\"rule\",\"expr\":\"(P[i] = L4)\",\"label\":\"L4_execute_critical_and_assign_Qi_1\",\"loc\":{\"$type\":\"location\",\"file\":\"/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/tests/n_peterson.hard-bug.m\",\"start\":[134,3],\"end\":[143,6]}"},};

}

/* ======= Romp CALLER Lists ====== */
namespace __caller__ {
  typedef ::__model__::__Model__ State_t; // type mask for the generated state object
  /* --- Rules Generated by: `L0_execute_inc_j_and_while` (RuleSet expansions) --- */
   bool __Rule_guard__L0_execute_inc_j_and_while__0(const State_t& s){return s.__Rule_guard__L0_execute_inc_j_and_while((::__type__::pid) 0); }
   void __Rule_action__L0_execute_inc_j_and_while__0(State_t& s){s.__Rule_action__L0_execute_inc_j_and_while((::__type__::pid) 0); }
   bool __Rule_guard__L0_execute_inc_j_and_while__1(const State_t& s){return s.__Rule_guard__L0_execute_inc_j_and_while((::__type__::pid) 1); }
   void __Rule_action__L0_execute_inc_j_and_while__1(State_t& s){s.__Rule_action__L0_execute_inc_j_and_while((::__type__::pid) 1); }
   bool __Rule_guard__L0_execute_inc_j_and_while__2(const State_t& s){return s.__Rule_guard__L0_execute_inc_j_and_while((::__type__::pid) 2); }
   void __Rule_action__L0_execute_inc_j_and_while__2(State_t& s){s.__Rule_action__L0_execute_inc_j_and_while((::__type__::pid) 2); }
   bool __Rule_guard__L0_execute_inc_j_and_while__3(const State_t& s){return s.__Rule_guard__L0_execute_inc_j_and_while((::__type__::pid) 3); }
   void __Rule_action__L0_execute_inc_j_and_while__3(State_t& s){s.__Rule_action__L0_execute_inc_j_and_while((::__type__::pid) 3); }
  /* --- Rules Generated by: `L1_execute_assign_Qi_j` (RuleSet expansions) --- */
   bool __Rule_guard__L1_execute_assign_Qi_j__0(const State_t& s){return s.__Rule_guard__L1_execute_assign_Qi_j((::__type__::pid) 0); }
   void __Rule_action__L1_execute_assign_Qi_j__0(State_t& s){s.__Rule_action__L1_execute_assign_Qi_j((::__type__::pid) 0); }
   bool __Rule_guard__L1_execute_assign_Qi_j__1(const State_t& s){return s.__Rule_guard__L1_execute_assign_Qi_j((::__type__::pid) 1); }
   void __Rule_action__L1_execute_assign_Qi_j__1(State_t& s){s.__Rule_action__L1_execute_assign_Qi_j((::__type__::pid) 1); }
   bool __Rule_guard__L1_execute_assign_Qi_j__2(const State_t& s){return s.__Rule_guard__L1_execute_assign_Qi_j((::__type__::pid) 2); }
   void __Rule_action__L1_execute_assign_Qi_j__2(State_t& s){s.__Rule_action__L1_execute_assign_Qi_j((::__type__::pid) 2); }
   bool __Rule_guard__L1_execute_assign_Qi_j__3(const State_t& s){return s.__Rule_guard__L1_execute_assign_Qi_j((::__type__::pid) 3); }
   void __Rule_action__L1_execute_assign_Qi_j__3(State_t& s){s.__Rule_action__L1_execute_assign_Qi_j((::__type__::pid) 3); }
  /* --- Rules Generated by: `L2_execute_assign_TURNj_i` (RuleSet expansions) --- */
   bool __Rule_guard__L2_execute_assign_TURNj_i__0(const State_t& s){return s.__Rule_guard__L2_execute_assign_TURNj_i((::__type__::pid) 0); }
   void __Rule_action__L2_execute_assign_TURNj_i__0(State_t& s){s.__Rule_action__L2_execute_assign_TURNj_i((::__type__::pid) 0); }
   bool __Rule_guard__L2_execute_assign_TURNj_i__1(const State_t& s){return s.__Rule_guard__L2_execute_assign_TURNj_i((::__type__::pid) 1); }
   void __Rule_action__L2_execute_assign_TURNj_i__1(State_t& s){s.__Rule_action__L2_execute_assign_TURNj_i((::__type__::pid) 1); }
   bool __Rule_guard__L2_execute_assign_TURNj_i__2(const State_t& s){return s.__Rule_guard__L2_execute_assign_TURNj_i((::__type__::pid) 2); }
   void __Rule_action__L2_execute_assign_TURNj_i__2(State_t& s){s.__Rule_action__L2_execute_assign_TURNj_i((::__type__::pid) 2); }
   bool __Rule_guard__L2_execute_assign_TURNj_i__3(const State_t& s){return s.__Rule_guard__L2_execute_assign_TURNj_i((::__type__::pid) 3); }
   void __Rule_action__L2_execute_assign_TURNj_i__3(State_t& s){s.__Rule_action__L2_execute_assign_TURNj_i((::__type__::pid) 3); }
  /* --- Rules Generated by: `L3_execute_wait_until` (RuleSet expansions) --- */
   bool __Rule_guard__L3_execute_wait_until__0(const State_t& s){return s.__Rule_guard__L3_execute_wait_until((::__type__::pid) 0); }
   void __Rule_action__L3_execute_wait_until__0(State_t& s){s.__Rule_action__L3_execute_wait_until((::__type__::pid) 0); }
   bool __Rule_guard__L3_execute_wait_until__1(const State_t& s){return s.__Rule_guard__L3_execute_wait_until((::__type__::pid) 1); }
   void __Rule_action__L3_execute_wait_until__1(State_t& s){s.__Rule_action__L3_execute_wait_until((::__type__::pid) 1); }
   bool __Rule_guard__L3_execute_wait_until__2(const State_t& s){return s.__Rule_guard__L3_execute_wait_until((::__type__::pid) 2); }
   void __Rule_action__L3_execute_wait_until__2(State_t& s){s.__Rule_action__L3_execute_wait_until((::__type__::pid) 2); }
   bool __Rule_guard__L3_execute_wait_until__3(const State_t& s){return s.__Rule_guard__L3_execute_wait_until((::__type__::pid) 3); }
   void __Rule_action__L3_execute_wait_until__3(State_t& s){s.__Rule_action__L3_execute_wait_until((::__type__::pid) 3); }
  /* --- Rules Generated by: `L4_execute_critical_and_assign_Qi_1` (RuleSet expansions) --- */
   bool __Rule_guard__L4_execute_critical_and_assign_Qi_1__0(const State_t& s){return s.__Rule_guard__L4_execute_critical_and_assign_Qi_1((::__type__::pid) 0); }
   void __Rule_action__L4_execute_critical_and_assign_Qi_1__0(State_t& s){s.__Rule_action__L4_execute_critical_and_assign_Qi_1((::__type__::pid) 0); }
   bool __Rule_guard__L4_execute_critical_and_assign_Qi_1__1(const State_t& s){return s.__Rule_guard__L4_execute_critical_and_assign_Qi_1((::__type__::pid) 1); }
   void __Rule_action__L4_execute_critical_and_assign_Qi_1__1(State_t& s){s.__Rule_action__L4_execute_critical_and_assign_Qi_1((::__type__::pid) 1); }
   bool __Rule_guard__L4_execute_critical_and_assign_Qi_1__2(const State_t& s){return s.__Rule_guard__L4_execute_critical_and_assign_Qi_1((::__type__::pid) 2); }
   void __Rule_action__L4_execute_critical_and_assign_Qi_1__2(State_t& s){s.__Rule_action__L4_execute_critical_and_assign_Qi_1((::__type__::pid) 2); }
   bool __Rule_guard__L4_execute_critical_and_assign_Qi_1__3(const State_t& s){return s.__Rule_guard__L4_execute_critical_and_assign_Qi_1((::__type__::pid) 3); }
   void __Rule_action__L4_execute_critical_and_assign_Qi_1__3(State_t& s){s.__Rule_action__L4_execute_critical_and_assign_Qi_1((::__type__::pid) 3); }

/* the number of rules in the model, AFTER ruleset expansion */
#define _ROMP_RULE_COUNT (20ul)


  // All of the rule sets in one place
  const ::romp::RuleSet RULESETS[_ROMP_RULESETS_LEN] = {
		{::__info__::RULE_SET_INFOS[0],std::vector<::romp::Rule>{::romp::Rule{__Rule_guard__L0_execute_inc_j_and_while__0,__Rule_action__L0_execute_inc_j_and_while__0,::__info__::RULE_SET_INFOS[0],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":0}}]","i:=0"}, ::romp::Rule{__Rule_guard__L0_execute_inc_j_and_while__1,__Rule_action__L0_execute_inc_j_and_while__1,::__info__::RULE_SET_INFOS[0],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":1}}]","i:=1"}, ::romp::Rule{__Rule_guard__L0_execute_inc_j_and_while__2,__Rule_action__L0_execute_inc_j_and_while__2,::__info__::RULE_SET_INFOS[0],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":2}}]","i:=2"}, ::romp::Rule{__Rule_guard__L0_execute_inc_j_and_while__3,__Rule_action__L0_execute_inc_j_and_while__3,::__info__::RULE_SET_INFOS[0],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":3}}]","i:=3"}  	}},
		{::__info__::RULE_SET_INFOS[1],std::vector<::romp::Rule>{::romp::Rule{__Rule_guard__L1_execute_assign_Qi_j__0,__Rule_action__L1_execute_assign_Qi_j__0,::__info__::RULE_SET_INFOS[1],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":0}}]","i:=0"}, ::romp::Rule{__Rule_guard__L1_execute_assign_Qi_j__1,__Rule_action__L1_execute_assign_Qi_j__1,::__info__::RULE_SET_INFOS[1],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":1}}]","i:=1"}, ::romp::Rule{__Rule_guard__L1_execute_assign_Qi_j__2,__Rule_action__L1_execute_assign_Qi_j__2,::__info__::RULE_SET_INFOS[1],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":2}}]","i:=2"}, ::romp::Rule{__Rule_guard__L1_execute_assign_Qi_j__3,__Rule_action__L1_execute_assign_Qi_j__3,::__info__::RULE_SET_INFOS[1],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":3}}]","i:=3"}  	}},
		{::__info__::RULE_SET_INFOS[2],std::vector<::romp::Rule>{::romp::Rule{__Rule_guard__L2_execute_assign_TURNj_i__0,__Rule_action__L2_execute_assign_TURNj_i__0,::__info__::RULE_SET_INFOS[2],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":0}}]","i:=0"}, ::romp::Rule{__Rule_guard__L2_execute_assign_TURNj_i__1,__Rule_action__L2_execute_assign_TURNj_i__1,::__info__::RULE_SET_INFOS[2],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":1}}]","i:=1"}, ::romp::Rule{__Rule_guard__L2_execute_assign_TURNj_i__2,__Rule_action__L2_execute_assign_TURNj_i__2,::__info__::RULE_SET_INFOS[2],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":2}}]","i:=2"}, ::romp::Rule{__Rule_guard__L2_execute_assign_TURNj_i__3,__Rule_action__L2_execute_assign_TURNj_i__3,::__info__::RULE_SET_INFOS[2],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":3}}]","i:=3"}  	}},
		{::__info__::RULE_SET_INFOS[3],std::vector<::romp::Rule>{::romp::Rule{__Rule_guard__L3_execute_wait_until__0,__Rule_action__L3_execute_wait_until__0,::__info__::RULE_SET_INFOS[3],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":0}}]","i:=0"}, ::romp::Rule{__Rule_guard__L3_execute_wait_until__1,__Rule_action__L3_execute_wait_until__1,::__info__::RULE_SET_INFOS[3],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":1}}]","i:=1"}, ::romp::Rule{__Rule_guard__L3_execute_wait_until__2,__Rule_action__L3_execute_wait_until__2,::__info__::RULE_SET_INFOS[3],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":2}}]","i:=2"}, ::romp::Rule{__Rule_guard__L3_execute_wait_until__3,__Rule_action__L3_execute_wait_until__3,::__info__::RULE_SET_INFOS[3],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":3}}]","i:=3"}  	}},
		{::__info__::RULE_SET_INFOS[4],std::vector<::romp::Rule>{::romp::Rule{__Rule_guard__L4_execute_critical_and_assign_Qi_1__0,__Rule_action__L4_execute_critical_and_assign_Qi_1__0,::__info__::RULE_SET_INFOS[4],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":0}}]","i:=0"}, ::romp::Rule{__Rule_guard__L4_execute_critical_and_assign_Qi_1__1,__Rule_action__L4_execute_critical_and_assign_Qi_1__1,::__info__::RULE_SET_INFOS[4],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":1}}]","i:=1"}, ::romp::Rule{__Rule_guard__L4_execute_critical_and_assign_Qi_1__2,__Rule_action__L4_execute_critical_and_assign_Qi_1__2,::__info__::RULE_SET_INFOS[4],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":2}}]","i:=2"}, ::romp::Rule{__Rule_guard__L4_execute_critical_and_assign_Qi_1__3,__Rule_action__L4_execute_critical_and_assign_Qi_1__3,::__info__::RULE_SET_INFOS[4],"[{\"$type\":\"kv-pair\",\"key\":\"i\",\"value\":{\"$type\":\"scalarset-value\",\"type\":\"pid\",\"value\":3}}]","i:=3"}  	}}};

  /* --- Property Rule(s) generated by: `only_one_P_has_lock` (RuleSet expansions) --- */
   bool __Property__only_one_P_has_lock__0(const State_t& s) {return s.__Property__only_one_P_has_lock(); }
  /* --- Property Rule(s) generated by: `injected_hist_subseq_bug` (RuleSet expansions) --- */
   bool __Property__injected_hist_subseq_bug__0(const State_t& s) {return s.__Property__injected_hist_subseq_bug(); }

#ifdef __romp__ENABLE_assume_property
#define ___propRule_assume_count___ (0ul)
#else
#define ___propRule_assume_count___ (0ul)
#endif
#ifdef __romp__ENABLE_cover_property
#define ___propRule_cover_count___ (0ul)
#else
#define ___propRule_cover_count___ (0ul)
#endif
#ifdef __romp__ENABLE_liveness_property
#define ___propRule_liveness_count___ (0ul)
#else
#define ___propRule_liveness_count___ (0ul)
#endif

/* the number of property rules (after ruleset expansion) in the model */
#define _ROMP_PROPERTY_RULES_LEN ((2ul) + ___propRule_assume_count___ + ___propRule_cover_count___ + ___propRule_liveness_count___)

  /* All of the property rules expanded in one place */
const ::romp::Property PROPERTIES[_ROMP_PROPERTY_RULES_LEN] = {
		{__Property__only_one_P_has_lock__0,::__info__::PROPERTY_INFOS[0],"[]",""},
		{__Property__injected_hist_subseq_bug__0,::__info__::PROPERTY_INFOS[1],"[]",""},
};

  /* --- StartState Rule(s) generated by: `init` (RuleSet expansions) --- */
   void __StartState__init__0(State_t& s){ s.__StartState__init(); }


#define _ROMP_STARTSTATES_LEN (1ul) // the number of property rules (after ruleset expansion) in the model

  // All of the rule sets in one place
const ::romp::StartState STARTSTATES[_ROMP_STARTSTATES_LEN] = {{__StartState__init__0,::__info__::STARTSTATE_INFOS[0],0,"[]",""}};


}



#pragma endregion generated_code


#pragma region romp_rw

#include "/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/resources/romp-rw.hpp"

#pragma endregion romp_rw


#pragma region romp_rw_options

#include "/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/resources/romp-rw-options.hpp"

#pragma endregion romp_rw_options


#pragma region romp_rw_main

#include "/mnt/g/My Drive/School/UofU/proj/romp/rumur-romp/romp/resources/romp-rw-main.hpp"

#pragma endregion romp_rw_main
