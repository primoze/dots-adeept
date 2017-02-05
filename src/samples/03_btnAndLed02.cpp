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
#include <dots-core/interrupts.h>

#include <dots-core/meta.h>

namespace samples {
namespace btnAndLed02 {


typedef os::compat::D11 led_pin;
typedef os::compat::D2 btn_pin;
typedef os::__lookup <btn_pin, os::compat::hwi_pin_map>::result hwi;


volatile bool state = false;

void state_change(void);

void btnAndLed02() {
    led_pin::set_mode(os::pin_mode::output);
    hwi::set_interrupt_handler(state_change, os::trigger_mode::falling);

    while (true) {
        led_pin::set_state(state);
    }
}

void state_change(void) {
    if(!btn_pin::get_state()) {
        os::util::delay_ms(10);
        if(!btn_pin::get_state()) {
            state = !state;
        }
    }
}


}
}
