//
// Created by marc on 26.10.15.
//

class LED : public actor
{
private:
    GPIO_Digital& 	_gpio_d;
    bool			_isOn;

public:

    /**
     * Constructor of the LED.
     */
    LED::LED(GPIO::GPIOPin& pin)
    {
        //TODO : Check if casting possible
        _gpio_d = (GPIO_Digital&)getGPIOResource(GPIO::GPIOType.DIGITAL, pin)

        off();

        //Set direction to output.
        _gpio_d.setDirection(GPIO::Direction.OUTPUT);



    }

    LED::~LED(void)
    {
        //TODO Unexport the pin once finished.
    }


    /**
     * Switch the LED on.
     */
    void on()
    {
        //Set value to 1/Toggle the LED on.
        _gpio_d.setValue(GPIO_Digital::State.HIGH);

        _isOn = true;
    }


    /**
     * Switch the LED off.
     */
    void off()
    {
        //Set value to 0/Toggle the LED off.
        _gpio_d.setValue(GPIO_Digital::State.LOW);

        _isOn = false;
    }

    /**
     * Toggle between on and off.
     */
    void toggle()
    {
        if(_isOn)
        {
            off(); //If on switch off
        }
        else
        {
            on(); //If off switch on
        }
    }
};
