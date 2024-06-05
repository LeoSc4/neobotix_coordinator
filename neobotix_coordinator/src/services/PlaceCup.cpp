#include <neobotix_coordinator/services/MoveArmToPoseLin.h>

/**
 * @brief Set the name of the ROS2 service server to connect with.
 * @return Topic name as a string.
 */
std::string PlaceCup::ros2_service_name()
{
    return "/move_to_pose_lin";
}

/**
 * @brief Set the list of ports provided by the BT node.
 *
 * New port:
 *      direction = [BT::InputPort, BT::OutputPort, BT::BidirectionalPort]
 *      data_type = <[float, int, std::string]>
 *      name = ("name")
 *
 * @return List of provided ports.
 */
BT::PortsList PlaceCup::providedPorts()
{
    return {BT::InputPort<int16>("cup_id")};
}

/**
 * @brief Set the content of the request message which is sent to the ROS2 service server.
 */
void PlaceCup::on_send(std::shared_ptr<MoveArmToPoseLinSrv::Request> request)
{
    int16_t cup_id = ports.get_value<int16_t>("cup_id");
    float x_offset, y_offset, z_offset, q_x_offset, q_y_offset, q_z_offset, q_w_offset;

    switch ( cup_id )
      {
         case '1':
            x_offset = 0.0;
            y_offset = 0.0;
            z_offset = 0.0;
            q_x_offset = 0.0;
            q_y_offset = 0.0;
            q_z_offset = 0.0;
            q_w_offset = 0.0;
            uppercase_A++;
            break;
         case '2':
            x_offset = 0.0;
            y_offset = 0.0;
            z_offset = 0.0;
            q_x_offset = 0.0;
            q_y_offset = 0.0;
            q_z_offset = 0.0;
            q_w_offset = 0.0;
            lowercase_a++;
            break;
        case '3':
            x_offset = 0.0;
            y_offset = 0.0;
            z_offset = 0.0;
            q_x_offset = 0.0;
            q_y_offset = 0.0;
            q_z_offset = 0.0;
            q_w_offset = 0.0;
            lowercase_a++;
            break;
        case '4':
            x_offset = 0.0;
            y_offset = 0.0;
            z_offset = 0.0;
            q_x_offset = 0.0;
            q_y_offset = 0.0;
            q_z_offset = 0.0;
            q_w_offset = 0.0;
            lowercase_a++;
            break;
        case '5':  
            x_offset = 0.0;
            y_offset = 0.0;
            z_offset = 0.0;
            q_x_offset = 0.0;
            q_y_offset = 0.0;
            q_z_offset = 0.0;
            q_w_offset = 0.0;
            lowercase_a++;
            break;
        case '6':  
            x_offset = 0.0;
            y_offset = 0.0;
            z_offset = 0.0;
            q_x_offset = 0.0;
            q_y_offset = 0.0;
            q_z_offset = 0.0;
            q_w_offset = 0.0;
            lowercase_a++;
            break;
         default:
            other++;
    }
   


    request->pose.position.x = ports.get_value<float>("x");
    request->pose.position.y = ports.get_value<float>("y");
    request->pose.position.z = ports.get_value<float>("z");
    request->pose.orientation.x = ports.get_value<float>("q_x");
    request->pose.orientation.y = ports.get_value<float>("q_y");
    request->pose.orientation.z = ports.get_value<float>("q_z");
    request->pose.orientation.w = ports.get_value<float>("q_w");

    log("Move arm lin to pose (" + Converter::ftos(request->pose.position.x) + ", " + Converter::ftos(request->pose.position.y) + ", " + Converter::ftos(request->pose.position.z) + ")");
    log("Orientation (" + Converter::ftos(request->pose.orientation.x) + ", " + Converter::ftos(request->pose.orientation.y) + ", " + Converter::ftos(request->pose.orientation.z) + ", " + Converter::ftos(request->pose.orientation.w) + ")");
}

/**
 * @brief Define what happens when recieving the response from the ROS2 service server.
 */
bool PlaceCup::on_result(std::shared_ptr<MoveArmToPoseLinSrv::Response>, std::shared_ptr<MoveArmToPoseLinSrv::Request>)
{
    log("MoveArmToPoseLin completed");
    return true;
}