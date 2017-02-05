/*
 * Copyright 2017 Primoz Erjavec
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <dots-core/common.h>
#include <dots-core/compat.h>
#include <dots-core/util.h>


namespace samples {
namespace activeBuzzer {

typedef os::compat::D8 buzzer_pin;

void activeBuzzer() {
    buzzer_pin::set_mode(os::pin_mode::output);

    while (true) {
        buzzer_pin::set_state(true);
        os::util::delay_ms(2000);
        buzzer_pin::set_state(false);
        os::util::delay_ms(2000);
    }
}


}
}

