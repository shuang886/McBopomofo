//
// NodeAnchor.h
//
// Copyright (c) 2007-2010 Lukhnos D. Liu (http://lukhnos.org)
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//

#ifndef NODEANCHOR_H_
#define NODEANCHOR_H_

#include <vector>

#include "Node.h"

namespace Formosa {
namespace Gramambular {

struct NodeAnchor {
  const Node* node = nullptr;
  size_t location = 0;
  size_t spanningLength = 0;
  double accumulatedScore = 0.0;
};

inline std::ostream& operator<<(std::ostream& stream,
                                const NodeAnchor& anchor) {
  stream << "{@(" << anchor.location << "," << anchor.spanningLength << "),";
  if (anchor.node) {
    stream << *(anchor.node);
  } else {
    stream << "null";
  }
  stream << "}";
  return stream;
}

inline std::ostream& operator<<(std::ostream& stream,
                                const std::vector<NodeAnchor>& anchor) {
  for (std::vector<NodeAnchor>::const_iterator i = anchor.begin();
       i != anchor.end(); ++i) {
    stream << *i;
    if (i + 1 != anchor.end()) {
      stream << "<-";
    }
  }

  return stream;
}
}  // namespace Gramambular
}  // namespace Formosa

#endif
