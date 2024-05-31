# CMakeList.txt : CMake project for PROJECTLAST, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("PROJECTLAST")

# Add source to this project's executable.
add_executable (PROJECTLAST "PROJECTLAST.cpp"  "PaymentSystem/PaymentSystem.h"     "User/User.h" "User/User.cpp" "Menu/UserMenu/UserMenu.h" "Interface/mainInteface.h" "FileSystm/CreditFileSyst/CreditFileSyst.h" "FileSystm/DebetFile/DebetFileSyst.h" "FileSystm/UserFile/UserFileSyst.h" "DebetCard/DebetCard.h" "DebetCard/DebetCard.cpp" "CreditCard/CreditCard.h" "CreditCard/CreditCard.cpp"   "Ratings/Ratings.cpp"  )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PROJECTLAST PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
