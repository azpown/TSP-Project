add_executable(TSPsolv main.c )
target_link_libraries (TSPsolv Input BFO FonctionTest NN Prim)

install(TARGETS TSPsolv DESTINATION ${TSP_BINARY_DIR}/bin)
