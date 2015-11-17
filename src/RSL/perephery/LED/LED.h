//
// Created by Marc on 09.11.2015.
//

    #ifndef RESYLIB_LED_H
    #define RESYLIB_LED_H

    #include "../actor.h"

    namespace RSL {

        class LED : public Actor {

        private:

            /**
             * remembers whether the LED is on (true = on)
             */
            bool _isOn;

            /**
             * The GPIO pin used by the LD.
             */
            GPIO_Digital& _gpio_d;

        public:

            /**
             * Constructor for the LED, the given pin will be registered.
             */
            LED(GPIOPin& pin);

            /**
             * Switches the LED on.
             */
            void on();

            /**
             * Switches the LED off.
             */
            void off();

            /**
             * If on switches off, if off switches on.
             */
            void toggle();

            /**
             * Destructor that unregisters the GPIO-pin
             */
            ~LED();
        };

    }

    #endif //RESYLIB_LED_H





}