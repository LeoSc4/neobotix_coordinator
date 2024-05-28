#include <neobotix_coordinator/services/GetArucoPosition.h>

/**
 * @brief Set the name of the ROS2 service server to connect with.
 * @return Topic name as a string.
*/
std::string GetArucoPosition::ros2_service_name()
{
    return "/get_aruco_pose";
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
BT::PortsList GetArucoPosition::providedPorts()
{
    return {BT::InputPort<int>("aruco_id")};
}

/**
 * @brief Set the content of the request message which is sent to the ROS2 service server.
 */
void GetArucoPosition::on_send(std::shared_ptr<GetArucoPositionSrv::Request> request)
{
    request->aruco_id = ports.get_value<int>("aruco_id");

    log("GetArucoPosition for Aruco ID " + Converter::ftos(request->aruco_id) + ".");
}

/**
 * @brief Define what happens when recieving the response from the ROS2 service server.
 */
bool GetArucoPosition::on_result(std::shared_ptr<GetArucoPositionSrv::Response>, std::shared_ptr<GetArucoPositionSrv::Request>)
{  
    log("GetArucoPosition completed");
    return true;
}


