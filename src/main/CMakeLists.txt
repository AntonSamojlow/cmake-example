# cmake file for src/main

# resolve external dependencies (vcpkg)
find_package(spdlog REQUIRED)

# get all source files
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.ixx)
set(SOURCES ${SOURCES})

# combine dependencies in a variable
set(DEPENDENCIES spdlog::spdlog mylibrary)

# build target main: as executable
add_executable(main ${SOURCES})
target_link_libraries(main PRIVATE ${DEPENDENCIES})


if (USE_ADDRESS_SANITIZER)
	target_compile_options(main PUBLIC -fsanitize=address /Zi)
	target_link_options(main PRIVATE -fsanitize=address -fno-omit-frame-pointer)

	# see https://github.com/llvm/llvm-project/issues/56300 (and related solution https://stackoverflow.com/q/74186326)
	add_compile_definitions(_DISABLE_STRING_ANNOTATION=1 _DISABLE_VECTOR_ANNOTATION=1)

	# remember to add location of clang_rt.* dlls  to PATH - for x64, this is currently:
	target_link_directories(main PRIVATE "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.34.31933/bin/Hostx64/x64")

	# location of (x64) asan_dbg_dynamic_runtime_thunk:
	# target_link_directories(main PRIVATE "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/x64/lib/clang/15.0.1/lib/windows")

	# Clang:
	if(IS_CLANG_CL)
		if(CMAKE_BUILD_TYPE STREQUAL Release)
			target_link_libraries(main PRIVATE clang_rt.asan_dynamic-x86_64 clang_rt.asan_dynamic_runtime_thunk-x86_64)
			target_link_options(main PRIVATE /wholearchive:clang_rt.asan_dynamic_runtime_thunk-x86_64.lib)	
		elseif(CMAKE_BUILD_TYPE STREQUAL Debug)
			target_link_libraries(main PRIVATE clang_rt.asan_dbg_dynamic-x86_64 clang_rt.asan_dbg_dynamic_runtime_thunk-x86_64)
			target_link_options(main PRIVATE /wholearchive:clang_rt.asan_dbg_dynamic_runtime_thunk-x86_64.lib)
		endif()	
	endif()

endif()


# build target main_lib: as lib to be consumed by tests (is there a better solution?)
add_library(main_lib ${SOURCES})
target_link_libraries(main_lib PRIVATE ${DEPENDENCIES})
 