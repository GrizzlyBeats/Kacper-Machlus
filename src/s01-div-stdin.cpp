auto main() -> int
{
   auto const a = ask_user_for_integer("a = ");
   auto const b = ask_user_for_integer("a = ");
   std::cout << (a / b) << "\n";
   return 0;
}
