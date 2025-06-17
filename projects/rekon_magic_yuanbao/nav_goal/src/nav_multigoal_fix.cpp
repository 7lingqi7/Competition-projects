#include"ros/ros.h"//包含ROS头文件  
#include <move_base_msgs/MoveBaseAction.h>//包含move_base action头文件  
#include <actionlib/client/simple_action_client.h>//包含simple_aciton客户端头文件  
#include <relative_move/SetRelativeMove.h>
#include <ar_pose/Track.h>

#include <chrono>
#include <thread>

#include <string>

main(int argc,char** argv)  
{   
   ros::init(argc,argv,"nav_multigoal_fix");  
   ros::NodeHandle n;  
   actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base",true);//定义一个acition客户端 
   
   
   // ros::ServiceClient relative_move_client = n.serviceClient<relative_move::SetRelativeMove>("relative_move");//定义相对运动客户端
   // ros::ServiceClient ar_track_client = n.serviceClient<ar_pose::Track>("track");//定义ar码跟踪客户端
   // relative_move::SetRelativeMove RelativeMove_data;
   // ar_pose::Track Track_data; 
   
   
   ac.waitForServer();//等待服务开启 

   // ros::service::waitForService("relative_move");//等待服务启动
   // ros::service::waitForService("track");//等待服务启动
   // std::cout<<"服务启动成功"<<std::endl;

   move_base_msgs::MoveBaseGoal goal1_pre;//定义第一个目标点 北京馆 
   goal1_pre.target_pose.header.frame_id = "map";  
   goal1_pre.target_pose.header.stamp = ros::Time::now();  
   goal1_pre.target_pose.pose.position.x = 2.28;//目标点x 
   goal1_pre.target_pose.pose.position.y = 0.13;//目标点y  
   goal1_pre.target_pose.pose.orientation.z = 0.03;
   goal1_pre.target_pose.pose.orientation.w = 0.99;//目标点姿态四元数表示 
   move_base_msgs::MoveBaseGoal goal1;//定义第一个目标点 北京馆 
   goal1.target_pose.header.frame_id = "map";  
   goal1.target_pose.header.stamp = ros::Time::now();  
   goal1.target_pose.pose.position.x = 2.537;//目标点x 
   goal1.target_pose.pose.position.y = 0.136;//目标点y  
   goal1.target_pose.pose.orientation.z =0.038;
   goal1.target_pose.pose.orientation.w = 0.998;//目标点姿态四元数表示

   move_base_msgs::MoveBaseGoal goal2_pre;//定义第二个目标点 ，广州馆 
   goal2_pre.target_pose.header.frame_id = "map";  
   goal2_pre.target_pose.header.stamp = ros::Time::now();  
   goal2_pre.target_pose.pose.position.x = 2.28;//目标点x  
   goal2_pre.target_pose.pose.position.y = 1.077; //目标点y  
   goal2_pre.target_pose.pose.orientation.z = -0.026;  
   goal2_pre.target_pose.pose.orientation.w = 1.000;//目标点姿态四元数表示  
   move_base_msgs::MoveBaseGoal goal2;//定义第二个目标点 ，广州馆 
   goal2.target_pose.header.frame_id = "map";  
   goal2.target_pose.header.stamp = ros::Time::now();  
   goal2.target_pose.pose.position.x = 2.527;//目标点x  
   goal2.target_pose.pose.position.y =1.158; //目标点y  
   goal2.target_pose.pose.orientation.z =  -0.026;  
   goal2.target_pose.pose.orientation.w =1.000;//目标点姿态四元数表示   

   move_base_msgs::MoveBaseGoal goal3_pre;//定义第三个目标点 ，吉林馆 
   goal3_pre.target_pose.header.frame_id = "map";  
   goal3_pre.target_pose.header.stamp = ros::Time::now();  
   goal3_pre.target_pose.pose.position.x = 2.28;//目标点x  
   goal3_pre.target_pose.pose.position.y = 2.120;    //目标点y  
   goal3_pre.target_pose.pose.orientation.z = -0.032;  
   goal3_pre.target_pose.pose.orientation.w = 0.999;//目标点姿态四元数表示
   move_base_msgs::MoveBaseGoal goal3;//定义第三个目标点 ，吉林馆 
   goal3.target_pose.header.frame_id = "map";  
   goal3.target_pose.header.stamp = ros::Time::now();  
   goal3.target_pose.pose.position.x = 2.500;//目标点x  
   goal3.target_pose.pose.position.y = 2.136;    //目标点y  
   goal3.target_pose.pose.orientation.z = 0.039;  
   goal3.target_pose.pose.orientation.w =0.999;//目标点姿态四元数表示

   move_base_msgs::MoveBaseGoal goal4_pre;//定义第四个目标点 ，深圳馆 
   goal4_pre.target_pose.header.frame_id = "map";  
   goal4_pre.target_pose.header.stamp = ros::Time::now();  
   goal4_pre.target_pose.pose.position.x =0.826;//目标点x  
   goal4_pre.target_pose.pose.position.y = 1.109;    //目标点y  
   goal4_pre.target_pose.pose.orientation.z = -0.012;  
   goal4_pre.target_pose.pose.orientation.w = 1.000;//目标点姿态四元数表示
   move_base_msgs::MoveBaseGoal goal4;//定义第四个目标点 ，深圳馆 
   goal4.target_pose.header.frame_id = "map";  
   goal4.target_pose.header.stamp = ros::Time::now();  
   goal4.target_pose.pose.position.x =1.059;//目标点x  
   goal4.target_pose.pose.position.y =  1.113;    //目标点y  
   goal4.target_pose.pose.orientation.z = -0.039;  
   goal4.target_pose.pose.orientation.w =0.999;//目标点姿态四元数表示


   move_base_msgs::MoveBaseGoal goal5_pre;//定义第五个目标点 ，上海馆 
   goal5_pre.target_pose.header.frame_id = "map";  
   goal5_pre.target_pose.header.stamp = ros::Time::now();  
   goal5_pre.target_pose.pose.position.x =0.873;//目标点x  
   goal5_pre.target_pose.pose.position.y = 2.120;    //目标点y  
   goal5_pre.target_pose.pose.orientation.z =0.013;  
   goal5_pre.target_pose.pose.orientation.w = 1.000;//目标点姿态四元数表示
   move_base_msgs::MoveBaseGoal goal5;//定义第五个目标点 ，上海馆 
   goal5.target_pose.header.frame_id = "map";  
   goal5.target_pose.header.stamp = ros::Time::now();  
   goal5.target_pose.pose.position.x =1.069;//目标点x  
   goal5.target_pose.pose.position.y = 2.099;    //目标点y  
   goal5.target_pose.pose.orientation.z =-0.028;  
   goal5.target_pose.pose.orientation.w = 1.000;//目标点姿态四元数表示

   // 回到终点
   move_base_msgs::MoveBaseGoal goal6_pre;//定义第六个目标点
   goal6_pre.target_pose.header.frame_id = "map";  
   goal6_pre.target_pose.header.stamp = ros::Time::now();  
   goal6_pre.target_pose.pose.position.x =0.275;//目标点x  
   goal6_pre.target_pose.pose.position.y = 0.006;    //目标点y  
   goal6_pre.target_pose.pose.orientation.z = 0.00;
   goal6_pre.target_pose.pose.orientation.w = 1.000;//目标点姿态四元数表示
   move_base_msgs::MoveBaseGoal goal6;//定义第六个目标点 终点
   goal6.target_pose.header.frame_id = "map";  
   goal6.target_pose.header.stamp = ros::Time::now();  
   goal6.target_pose.pose.position.x =0.013;//目标点x  
   goal6.target_pose.pose.position.y = 0.001;    //目标点y  
   goal6.target_pose.pose.orientation.z =-0.002;
   goal6.target_pose.pose.orientation.w = 1.000;//目标点姿态四元数表示


   // 转角点（防止撞墙）
   move_base_msgs::MoveBaseGoal turn;//定义第六个目标点
   turn.target_pose.header.frame_id = "map";  
   turn.target_pose.header.stamp = ros::Time::now();  
   turn.target_pose.pose.position.x =1.937;//目标点x  
   turn.target_pose.pose.position.y = 0.006;    //目标点y  
   turn.target_pose.pose.orientation.z = -0.101;
   turn.target_pose.pose.orientation.w = 0.995;//目标点姿态四元数表示
 

  int Num = 1;//定义巡检的圈数  
  for(int i=0;i<Num;i++)  
{  



  

   



   // // 转角点1
   // ac.sendGoal(turn);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //     {  
   //     usleep(1000*20);  
   //     }  
   // ROS_INFO("机器人到达目标点1");






   // // 转角点1
   // ac.sendGoal(turn);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //     {  
   //     usleep(1000*20);  
   //     }  
   // ROS_INFO("机器人到达目标点1");



    // 北京馆
   ac.sendGoal(goal1_pre);  
   while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
      {  
      usleep(1000*20);  
      } 
   ROS_INFO("机器人到达目标点1");  
   ac.sendGoal(goal1);  
   while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
      {  
      usleep(1000*20);  
      }  
   ROS_INFO("机器人到达目标点1"); 



   // // 深圳馆
   // ac.sendGoal(goal4_pre);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //    {  
   //    usleep(1000*20);  
   //    }  
   // ROS_INFO("机器人到达目标点1");  
   // ac.sendGoal(goal4);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //    {  
   //    usleep(1000*20);  
   //    }  
   // ROS_INFO("机器人到达目标点4");

   // // 上海馆
   // ac.sendGoal(goal5_pre);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //    { 
   //    usleep(1000*20);  
   //    }  
   // ROS_INFO("机器人到达目标点1");  
   // ac.sendGoal(goal5);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //    {  
   //    usleep(1000*20);  
   //    }  
   // ROS_INFO("机器人到达目标点5");



   //     // 广州馆
   // ac.sendGoal(goal2_pre);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //    {  
   //    usleep(1000*20);  
   //    }  
   // ROS_INFO("机器人到达目标点1");  
   // ac.sendGoal(goal2);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //    {  
   //    usleep(1000*20);  
   //    }  
   // ROS_INFO("机器人到达目标点2"); 


   // // 吉林馆
   // ac.sendGoal(goal3_pre);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //    {  
   //    usleep(1000*20);  
   //    }  
   // ROS_INFO("机器人到达目标点1");  
   // ac.sendGoal(goal3);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //    {  
   //    usleep(1000*20);  
   //    }  
   // ROS_INFO("机器人到达目标点3");

    

   
   // // 测试二次定位
   // int x = 0;
   //  while(x == 0){
   //      ar_track_client.call(Track_data);//调用服务
   //      if(!Track_data.response.success){
            
   //          std::cout<<"对准失败"<<std::endl;
   //          continue;
   //      }
   //      std::cout<<"对准完成"<<std::endl;
   //      x = 1;
        

   //  }


    // Track_data.request.angle = 2; // 设置期望的角度或方向
    // ar_track_client.call(Track_data);//调用服务
    
    //定义请求值
    // RelativeMove_data.request.goal.x = 0.0;
    // RelativeMove_data.request.global_frame = "odom";

    // relative_move_client.call(RelativeMove_data);//调用服务
    
    // std::cout<<"定位完成"<<std::endl;
    // std::cout<<"现在退出程序"<<std::endl;

   
   // 等待两秒
   std::this_thread::sleep_for(std::chrono::seconds(2));

   ROS_INFO("已等待两秒");


 

  

   




   
   

    


    
   // // 转角点1
   // ac.sendGoal(turn);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //     {  
   //     usleep(1000*20);  
   //     }  
   // ROS_INFO("机器人到达目标点1"); 

   // // 转角点2
   // ac.sendGoal(goal6_pre);  
   // while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
   //     {  
   //     usleep(1000*20);  
   //     }  
   // ROS_INFO("机器人到达目标点1"); 

   


   


   // 终点
   ac.sendGoal(goal6_pre);  
   while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
      {  
      usleep(1000*20);  
      }  
   ROS_INFO("机器人到达目标点1");  
   ac.sendGoal(goal6);  
   while(!(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED))  
      {  
      usleep(1000*20);  
      }  
   ROS_INFO("机器人到达目标点5"); 
 }  
  return 0;  
}  
