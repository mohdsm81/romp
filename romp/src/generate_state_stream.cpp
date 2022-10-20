/**
 * @proj romp
 * @author Andrew Osterhout
 * @author Ajantha Varadharaaj
 * @org University of Utah (UofU) School of Computing (SoC)
 * @org Center for Parallel compute at Utah (CPU)
 * @org <a href="https://civic-fv.github.io">Civic-fv NSF Grant</a>
 * @org Ganesh Gopalakrishnan's Research Group
 * @file generate_state_stream.cpp
 * 
 * @brief generate the stream operators used to output the state to json files or the console
 * 
 * @date 2022/10/19
 * @version 0.2
 */

#include "generate_state_stream.hpp"
#include "romp_def.hpp"
#include <murphi/murphi.h>
#include <sstream>
#include <cassert>


namespace romp {
  using namespace murphi;

void generate_state_stream(romp::ModelGenerator& gen, murphi::Model& m) {
  std::stringstream json;
  std::stringstream json_simp;
  std::string j_sep, p_sep;
  if (const auto _m = dynamic_cast<const Model*>(&n)) {
    gen << gen.indentation() << "friend inline " ROMP_OUT_STREAM_TYPE "& operator << (" ROMP_OUT_STREAM_TYPE "& out, const " ROMP_STATE_TYPE "& s) {\n";
    gen.indent();
    gen << gen.indentation() << " return (out << '{' << out.indent() << out.nl()";
    gen.indent(); gen.indent();
    for (const auto& c : _m->children) {
      if (const auto _vd = dynamic_cast<const VarDecl*>(c.get())) {
        json_simp << j_sep << " << s." << _vd->name;
        json << j_sep << " << \"{\\\"$type\\\":\\\"kv-pair\\\",\\\"key\\\":\\\"" << _vd->name <<  "\\\",\\\"value\\\":\" << \"s." << _vd->name >> "'}'";
        gen << p_sep << '\n' << gen.indentation() " << \"" << _vd->name << "\" "
                                                  "<< ((" ROMP_SHOW_TYPE_OPTION_EXPR ") ? \": \" + " << _vd->type << "::__p_type() + \" = \" : \" := \") "
                                                  "<< s." << _vd->name << " << ';'";
        j_sep = " << ','";
        p_sep = " << out.nl()";
      }
    }
    gen << '\n' << gen.indentation() << "<< out.dedent() << out.dedent() << out.nl() << '}';)";
    gen.dedent(); gen.dedent(); gen.dedent();
    gen << gen.indentation() << "}\n"
        << gen.indentation() << "inline ::std::ostream& operator << (::std::ostream& out_, const " ROMP_STATE_TYPE "& s) { "
                                  ROMP_OUT_STREAM_TYPE " out(out_,Options(),2); "
                                  "out << s; "
                                  "return out_; }\n";
    gen << "\n" << "#ifdef " ROMP_SIMPLE_TRACE_PREPROCESSOR_VAR "\n"
                << indentation() 
                << "template<class O> friend inline " ROMP_JSON_STREAM_TYPE "& operator << (" ROMP_JSON_STREAM_TYPE "& json, const " ROMP_STATE_TYPE "& s) { "
                      "json << '[' << " << json_simp_str() << " << ']'; return json; }\n"
                << "#else\n"
                << indentation() 
                << "template<class O> friend inline " ROMP_JSON_STREAM_TYPE "& operator << (" ROMP_JSON_STREAM_TYPE "& json, const " ROMP_STATE_TYPE "& s) { "
                      "return (json << \"{\\\"$type\\\":\\\"model-state\\\",\\\"value\\\":[\" << " << json.str() << " << \"]}\"); }\n"
                << "#endif\n"
  } else 
    assert(!"unreachable, node was not a Model");
}


} // namespace romp

