
/**
 * This file was generated by TONDev.
 * TONDev is a part of TON OS (see http://ton.dev).
 */

#include "Contract.hpp"
#include <tvm/contract.hpp>
#include <tvm/smart_switcher.hpp>
#include <tvm/contract_handle.hpp>
#include <tvm/replay_attack_protection/timestamp.hpp>
#include <tvm/default_support_functions.hpp>

#include "circuit.hpp"

using namespace tvm;
using namespace schema;

static constexpr unsigned TIMESTAMP_DELAY = 1800;

class CircuitUtil final : public smart_interface<ICircuitUtil>, public DCircuitUtil {
  using replay_protection_t = replay_attack_protection::timestamp<TIMESTAMP_DELAY>;
public:

  __always_inline
  void constructor() {
  }

  __always_inline
  Wittness generateWitness(uint32 a, uint32 x) {
    auto bp = generate_witness(a.get(), x.get());

    dict_array<uint8> pi_bb {};
    auto pi_writer = primary_input_writer(bp);
    auto pi_write_iter = pi_bb.begin();
    pi_writer.write(pi_write_iter, pi_writer.length());

    dict_array<uint8> ai_bb;
    auto ai_writer = auxiliary_input_writer(bp);
    auto ai_write_iter = ai_bb.begin();
    ai_writer.write(ai_write_iter, ai_writer.length());
    
    bytes primary_input;
    primary_input.assign(pi_bb.begin(), pi_bb.end());
    bytes auxiliary_input;    
    auxiliary_input.assign(ai_bb.begin(), ai_bb.end());

    Wittness w;
    w.primary_input = primary_input;
    w.auxiliary_input = auxiliary_input;
    return w;
  }

  // =============== Support functions ==================
  DEFAULT_SUPPORT_FUNCTIONS(ICircuitUtil, replay_protection_t)

  // default processing of unknown messages
  __always_inline static int _fallback(cell msg, slice msg_body) {
    return 0;
  }
};

DEFINE_JSON_ABI(ICircuitUtil, DCircuitUtil, ECircuitUtil);

// ----------------------------- Main entry functions ---------------------- //
DEFAULT_MAIN_ENTRY_FUNCTIONS(CircuitUtil, ICircuitUtil, DCircuitUtil, TIMESTAMP_DELAY)
