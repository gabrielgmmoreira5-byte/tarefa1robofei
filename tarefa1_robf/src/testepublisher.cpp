#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
//aqui em cima são algumas dependências

using namespace std::chrono_literals; //nos permite escrever os tempos de forma mais legível


class Publicadorobo : public rclcpp::Node //cria a classe do nó
{
public:
  Publicadorobo()
  : Node("publiquinha"), count_(0) //aqui é o nome do nó
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10); //cria um publisher que manda mensagens string no tópico "topic"
    timer_ = this->create_wall_timer(
      500ms, std::bind(&Publicadorobo::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = std_msgs::msg::String();
    message.data = "Vambora " + std::to_string(count_++); //cria a mensagem e publica no tópico
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_; //atributos privados
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Publicadorobo>()); //no main se inicializa, roda e encerra o sistema ros2
  rclcpp::shutdown();
  return 0;
}
