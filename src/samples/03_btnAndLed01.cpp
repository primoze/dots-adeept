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
namespace btnAndLed01 {


typedef os::compat::D11 led_pin;
typedef os::compat::D2 btn_pin;

volatile bool state = false;

void btnAndLed01() {
    led_pin::set_mode(os::pin_mode::output);
    btn_pin::set_mode(os::pin_mode::input);

    while (true) {
        if(!btn_pin::get_state()) {
            os::util::delay_ms(10);
            if(!btn_pin::get_state()) {
                while(!btn_pin::get_state()) { }
                os::util::delay_ms(10);
                while(!btn_pin::get_state()) { }
                state = !state;
                led_pin::set_state(state);
            }
        }
    }
}

}
}

