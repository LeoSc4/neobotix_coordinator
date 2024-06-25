#include <neobotix_coordinator/actions/MoveBaseToTable.h>

/**
 * @brief Set the name of the ROS2 action server to connect with.
 * @return Topic name as a string.
 */
std::string MoveBaseToTable::ros2_action_name()
{
    return "navigate_to_pose";
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
BT::PortsList MoveBaseToTable::providedPorts()
{
    return {BT::InputPort<int>("table_id") 
            };
            
}

/**
 * @brief Set the content of the goal message which is sent to the ROS2 action server.
 */
void MoveBaseToTable::on_send(MoveBaseToTableAction::Goal &goal)
{
    int requested_table_id = ports.get_value<int>("table_id");


    if (requested_table_id = 1)
    {
        goal.pose.header.frame_id = "map";
    
        goal.pose.pose.position.x = -5.136;
        // goal.pose.pose.position.x = ports.get_value<float>("x");
        //goal.pose.pose.position.y = 0.27507;
        goal.pose.pose.position.y = 0.67507;
        // goal.pose.pose.position.y = ports.get_value<float>("y");
        goal.pose.pose.position.z = 0; // z-value not neccessary
    
        goal.pose.pose.orientation.x = 0;
        goal.pose.pose.orientation.y = 0;
        goal.pose.pose.orientation.z = 1;
        goal.pose.pose.orientation.w = -0.105;

        goal.pose.header.stamp = get_node_handle()->now();

        log("Goal: (x=" + Converter::ftos(goal.pose.pose.position.x) + ", y=" + Converter::ftos(goal.pose.pose.position.y) + ")");
    }
    else
    {
        log("Note: No correct table id provided. Please request again.");
    }
   
}

/**
 * @brief Define what happens when recieving feedback from the ROS2 action server.
 */
void MoveBaseToTable::on_feedback(const std::shared_ptr<const MoveBaseToTableAction::Feedback>)
{
    // log("Current position: (x=" + Converter::ftos((float)feedback->current_pose.pose.position.x
    //     ", y=" + Converter::ftos((float)feedback->current_pose.pose.position.y) +
    //      "), Time elapsed: " + std::to_string(feedback->navigation_time.sec) + "s");
}

/**
 * @brief Define what happens when recieving the result from the ROS2 action server.
 */
void MoveBaseToTable::on_result(const rclcpp_action::ClientGoalHandle<MoveBaseToTableAction>::WrappedResult &, const MoveBaseToTableAction::Goal &goal)
{
    log("Goal reached! (x=" + Converter::ftos(goal.pose.pose.position.x) +
        ", y=" + Converter::ftos(goal.pose.pose.position.y) +
        "), Total time: " + std::to_string((int)get_node_handle()->now().seconds() - goal.pose.header.stamp.sec) + "s");
}