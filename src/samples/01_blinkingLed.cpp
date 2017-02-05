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
namespace blinkingLed {


//typedef os::compat::D8 led_pin;
//typedef os::port_b::_0 led_pin;
typedef os::compat::D8 led_pin;

void blinkingLed() {
    led_pin::set_mode(os::pin_mode::output);

    while (true) {
        led_pin::set_state(true);
//        PORTB |= _BV(0);
        os::util::delay_ms(1000);
        led_pin::set_state(false);
//        PORTB &= ~_BV(0);
        os::util::delay_ms(1000);
    }
}


}
}

