/** *******************************************************
 * IRAS - University of Applied Sciences Karlsruhe
 * Module : ROS2-Node "IRASCoordinator"
 * Purpose : Provides the ROS2-Service client "MoveURGripper"
 *
 * @author Andreas Zachariae
 * @since 1.0.0 (2023.05.19)
 *********************************************************/
#pragma once

#include <neobotix_coordinator/default.h>

#include <iras_behaviortree_ros2/components/RosService.h>
#include <ur_msgs/srv/set_io.hpp>


using MoveURGripperSrv = ur_msgs::srv::SetIO;

class MoveURGripper : public RosService<MoveURGripperSrv>
{
public:
    static BT::PortsList providedPorts();

    MoveURGripper(const std::string &name, const BT::NodeConfiguration &config) : RosService(name, config) {}

    std::string ros2_service_name() override;

    void on_send(std::shared_ptr<MoveURGripperSrv::Request> request) override;
    bool on_result(std::shared_ptr<MoveURGripperSrv::Response> response, std::shared_ptr<MoveURGripperSrv::Request> request) override;
};