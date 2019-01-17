/*******************************************************************************
* Copyright 2018 ROBOTIS CO., LTD.
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
*******************************************************************************/

/* Authors: Darby Lim, Hye-Jong KIM, Ryan Shim, Yong-Ho Na */

#ifndef LINEAR_TOOL_H_
#define LINEAR_TOOL_H_

#if defined(__OPENCR__)
  #include <RobotisManipulator.h>
  #include <DynamixelWorkbench.h>
#else
  #include <robotis_manipulator/robotis_manipulator.h>
  #include <dynamixel_workbench_toolbox/dynamixel_workbench.h>
#endif

namespace LINEAR_DYNAMIXEL
{

#define SYNC_WRITE_HANDLER_FOR_GOAL_POSITION 0
#define SYNC_READ_HANDLER_FOR_PRESENT_POSITION_VELOCITY_CURRENT 0

// Protocol 2.0
#define ADDR_PRESENT_CURRENT_2 126
#define ADDR_PRESENT_VELOCITY_2 128
#define ADDR_PRESENT_POSITION_2 132

#define LENGTH_PRESENT_CURRENT_2 2
#define LENGTH_PRESENT_VELOCITY_2 4
#define LENGTH_PRESENT_POSITION_2 4

// Protocol 1.0
#define ADDR_PRESENT_CURRENT_1 = 40;
#define ADDR_PRESENT_VELOCITY_1 = 38;
#define ADDR_PRESENT_POSITION_1 = 36;

#define LENGTH_PRESENT_CURRENT_1 = 2;
#define LENGTH_PRESENT_VELOCITY_1 = 2;
#define LENGTH_PRESENT_POSITION_1 = 2;

typedef struct
{
  std::vector<uint8_t> id;
  uint8_t num;
} Tool;

class ToolDynamixel : public ROBOTIS_MANIPULATOR::ToolActuator
{
private:
  DynamixelWorkbench *dynamixel_workbench_;
  Tool dynamixel_;

public:
  ToolDynamixel(){}
  virtual ~ToolDynamixel(){}

  virtual void init(uint8_t tool_id, const void *arg);
  virtual void setMode(const void *arg);
  virtual uint8_t getId();

  virtual void enable();
  virtual void disable();

  virtual bool sendToolActuatorValue(double value);
  virtual double receiveToolActuatorValue();

////////////////////////////////////////////////////////////////

  bool initialize(uint8_t tool_id, STRING dxl_device_name, STRING dxl_baud_rate);
  bool setOperatingMode(STRING dynamixel_mode = "position_mode");
  bool writeProfileValue(STRING profile_mode, uint32_t value);
  bool setSDKHandler();
  bool writeGoalPosition(double radian);
  double receiveDynamixelValue();
};

} // namespace LINEAR_DYNAMIXEL
#endif // LINEAR_TOOL_H_



