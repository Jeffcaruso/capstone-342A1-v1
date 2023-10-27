load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_cc//cc:defs.bzl", "cc_test")

cc_library(
  name = "APPLib",
  visibility = ["//visibility:public"],
  hdrs = glob(["**/*.h"]),
)

cc_library(
  name = "APP_src",
  visibility = ["//visibility:public"],
  srcs = glob(["pokedex.cpp"]),
  deps = ["//Inc:APPLib"],
)



cc_test(
  name = "APP_test",
  size = "small",
  srcs = glob(["Test1.cpp"]),
  copts = ["-Iexternal/gtest/include"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Inc:APPLib",
    "//Src:APP_src"
    ],
)

cc_test(
  name = "APP_test_2",
  size = "small",
  srcs = glob(["Test2.cpp"]),
  copts = ["-Iexternal/gtest/include"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Inc:APPLib",
    "//Src:APP_src"
    ],
)

cc_test(
  name = "APP_test_3",
  size = "small",
  srcs = glob(["Test3.cpp"]),
  copts = ["-Iexternal/gtest/include"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Inc:APPLib",
    "//Src:APP_src"
    ],
)

cc_test(
  name = "APP_test_4",
  size = "small",
  srcs = glob(["Test4.cpp"]),
  copts = ["-Iexternal/gtest/include"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Inc:APPLib",
    "//Src:APP_src"
    ],
)

cc_test(
  name = "APP_test_5",
  size = "small",
  srcs = glob(["Test5.cpp"]),
  copts = ["-Iexternal/gtest/include"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Inc:APPLib",
    "//Src:APP_src"
    ],
)

cc_test(
  name = "APP_test_6",
  size = "small",
  srcs = glob(["Test6.cpp"]),
  copts = ["-Iexternal/gtest/include"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Inc:APPLib",
    "//Src:APP_src"
    ],
)

cc_test(
  name = "APP_test_7",
  size = "small",
  srcs = glob(["Test7.cpp"]),
  copts = ["-Iexternal/gtest/include"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Inc:APPLib",
    "//Src:APP_src"
    ],
)

