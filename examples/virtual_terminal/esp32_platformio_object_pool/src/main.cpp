#include "isobus/hardware_integration/can_hardware_interface.hpp"
#include "isobus/hardware_integration/twai_plugin.hpp"
#include "isobus/isobus/can_general_parameter_group_numbers.hpp"
#include "isobus/isobus/can_network_manager.hpp"
#include "isobus/isobus/can_partnered_control_function.hpp"
#include "isobus/isobus/can_stack_logger.hpp"
#include "isobus/isobus/isobus_virtual_terminal_client.hpp"
#include "isobus/isobus/isobus_virtual_terminal_client_update_helper.hpp"
#include "isobus/utility/iop_file_interface.hpp"

#include "console_logger.cpp"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "objectPoolObjects.h"
#include "seeder.hpp"

#include <functional>
#include <iostream>
#include <memory>

extern "C" void app_main()
{
	Seeder seederExample;
	seederExample.initialize();

	while (true)
	{
		// CAN stack runs in other threads. Do nothing forever.
		seederExample.update();
		vTaskDelay(10);
	}
}
