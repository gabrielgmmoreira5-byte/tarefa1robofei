#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
//em cima são as inclusões iniciais
using std::placeholders::_1;

class Robosubscriba : public rclcpp::Node //define a classe do nó
{
public:
  Robosubscriba()
  : Node("subscribinha") //nome do nó
  {
    subscription_ = this->create_subscription<std_msgs::msg::String>( //cria o subscriber
      "topic", 10, std::bind(&Robosubscriba::topic_callback, this, _1));
  }

private:
  void topic_callback(const std_msgs::msg::String & msg) const
  {
    RCLCPP_INFO(this->get_logger(), "Recebi: '%s'", msg.data.c_str()); //esa parte é pra quando chega uma mensagem de um topic
  }
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Robosubscriba>()); //inicia e fecha o código
  rclcpp::shutdown();
  return 0;
}
