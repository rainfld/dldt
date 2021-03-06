// Copyright (C) 2018 Intel Corporation
//
// SPDX-License-Identifier: Apache-2.0
//

#include "iml_type_mapper.h"

using namespace MKLDNNPlugin;

impl_desc_type MKLDNNPlugin::parse_impl_name(std::string impl_desc_name) {
    impl_desc_type res = impl_desc_type::unknown;

#define SEARCH_WORD(_wrd) if (impl_desc_name.find(#_wrd) != std::string::npos) \
    res = static_cast<impl_desc_type>(res | impl_desc_type::_wrd);

    SEARCH_WORD(ref);
    SEARCH_WORD(jit);
    SEARCH_WORD(gemm);
    SEARCH_WORD(blas);
    SEARCH_WORD(sse42);
    SEARCH_WORD(avx2);
    SEARCH_WORD(avx512);
    SEARCH_WORD(any);
    SEARCH_WORD(_1x1);
    SEARCH_WORD(_dw);
    SEARCH_WORD(reorder);
#undef SEARCH_WORD

#define SEARCH_WORD_2(_wrd, _key) if (impl_desc_name.find(#_wrd) != std::string::npos) \
    res = static_cast<impl_desc_type>(res | impl_desc_type::_key);

    SEARCH_WORD_2(nchw, ref);
    SEARCH_WORD_2(wino, winograd);
#undef SEARCH_WORD_2

    return res;
}
