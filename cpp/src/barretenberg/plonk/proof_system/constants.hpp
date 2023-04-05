#pragma once
#include <cstdint>

namespace plonk {

enum ComposerType {
    STANDARD,
    TURBO,
    PLOOKUP,
    STANDARD_HONK, // Todo(Arijit): We should replace STANDARD_HONK outside plonk or the namespace should be bonk
};

// This variable sets the composer (TURBO or ULTRA) of the entire stdlib and rollup modules.
// To switch to using a new composer, only changing this variable should activate the new composer
// throughout the stdlib and circuits.
#ifdef USE_TURBO
static constexpr uint32_t SYSTEM_COMPOSER = ComposerType::TURBO;
#else
static constexpr uint32_t SYSTEM_COMPOSER = ComposerType::PLOOKUP;
#endif

enum MerkleHashType {
    FIXED_BASE_PEDERSEN,
    LOOKUP_PEDERSEN,
};

// limb size when simulating a non-native field using bigfield class
// (needs to be a universal constant to be used by native verifier)
static constexpr uint64_t NUM_LIMB_BITS_IN_FIELD_SIMULATION = 68;

static constexpr uint32_t NUM_QUOTIENT_PARTS = 4;
} // namespace plonk