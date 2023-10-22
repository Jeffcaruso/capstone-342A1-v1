load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "APP_src",
  visibility = ["//visibility:public"],
  srcs = glob(["**/*.cpp"]),
  hdrs = glob(["**/*.h"]),
  deps = ["//Inc:APPLib"],
)

