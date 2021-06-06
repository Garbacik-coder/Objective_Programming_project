cmake_minimum_required(VERSION 3.1)

project (GameTemplate)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)


# ustawienia SFML-a dla Linuksa/MacOS i Windows - proszę zostawić obie konfiguracje,
# CMake automatycznie użyje właściwej
if (UNIX)
    # proszę nie modyfkować pierwszego wpisu, można dopisać kolejne katalogi
    # pierwszy wpis powinien poprawnie skonfigurować SFML-a dla wszystkich
    # Debianopodobnych dystrybucji
    set ( CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

    # czy ktoś używa MacOS ? Co tam trzeba wpisać ?

endif(UNIX)

if (WIN32)
    # próbujemy linkować statycznie (nie trzeba kopiować plików dll do katalogu projektu)
    set( SFML_STATIC_LIBRARIES TRUE )

    # można zmienić katalog na właściwy
    set ( SFML_DIR "C:/SFML-2.5/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)


# to polecenie się wywali, jeśli CMake nie znajdzie SFML-a w jednym ze wskazanych
# wcześniej katalogów - nie ma potrzeby robienia potem if-a dla target_link_libraries
find_package(SFML 2 COMPONENTS graphics audio REQUIRED)


include_directories ( ${CMAKE_CURRENT_SOURCE_DIR} )

add_executable( GameTemplate main.cpp
 
	engine/GameManager.cpp
#	engine/GameStateController.cpp

        states/Scores/ScoresController.cpp
        states/Menu/MenuController.cpp

        states/GamePlay/GamePlayController.cpp states/GamePlay/GamePlayController.h GamePlay/GamePlay.cpp GamePlay/GamePlay.h GamePlay/Przeszkoda.cpp GamePlay/Przeszkoda.h GamePlay/Player.cpp GamePlay/Player.h states/OptionsContoller/OptionsController.cpp states/OptionsContoller/OptionsController.h)




target_link_libraries(GameTemplate sfml-system sfml-window sfml-graphics sfml-audio)







