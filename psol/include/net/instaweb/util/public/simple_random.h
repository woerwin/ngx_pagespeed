/*
 * Copyright 2013 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Author: jmarantz@google.com (Joshua Marantz)

#ifndef NET_INSTAWEB_UTIL_PUBLIC_SIMPLE_RANDOM_H_
#define NET_INSTAWEB_UTIL_PUBLIC_SIMPLE_RANDOM_H_

#include "net/instaweb/util/public/basictypes.h"
#include "net/instaweb/util/public/string.h"

namespace net_instaweb {

// Extremely simplistic pseudo-random number generator from
// http://www.codeproject.com/Articles/25172/Simple-Random-Number-Generation
//
// Do not use this for cryptographic applications.  This is intended
// for generating high-entropy data that will not compress easily.
class SimpleRandom {
 public:
  SimpleRandom() : z_(10), w_(25) {}
  ~SimpleRandom() {}
  int Next();

  GoogleString GenerateHighEntropyString(int size);

 private:
  uint32 z_;
  uint32 w_;

  // Copy & assign are OK.
};

}  // namespace net_instaweb

#endif  // NET_INSTAWEB_UTIL_PUBLIC_SIMPLE_RANDOM_H_
