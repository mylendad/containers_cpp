# Makefile for containers_cpp (header-only C++17 container library)
#
# Targets:
#   all          default: syntax-check headers + build tests (if gtest found)
#   check-headers  compile-only sanity check of the library headers
#   test_git | test_multiset | tests_tiltiset   build a single test binary
#   install      copy headers under $(PREFIX)/include/s21
#   uninstall    remove installed headers
#   clean        remove build artifacts
#   help         show this help

# --- Configuration ----------------------------------------------------------

CXX        ?= g++
CXXSTD     := c++17
WARNINGS   := -Wall -Wextra -Wpedantic
# Set FATAL_WARNINGS=yes to promote warnings to errors
ifeq ($(FATAL_WARNINGS),yes)
WARNINGS   += -Werror
endif
CXXFLAGS   ?= $(WARNINGS) -std=$(CXXSTD)

# Where library headers live
SRC_DIR    := src
LIB_HEADERS  := $(wildcard $(SRC_DIR)/*.h) $(wildcard $(SRC_DIR)/*.tpp)

# Build layout
BUILD_DIR  := build
BIN_DIR    := bin
GTEST_LIBS := -lgtest -lgtest_main -pthread

# Installation prefix
PREFIX     ?= /usr/local
INSTALL_DIR := $(DESTDIR)$(PREFIX)/include/s21

# --- Detection --------------------------------------------------------------

# GoogleTest is optional: tests build only when a usable gtest is present.
GTEST_INC  ?=
GTEST_H    := $(firstword $(wildcard /usr/include/gtest/gtest.h \
                                      /usr/local/include/gtest/gtest.h \
                                      $(if $(GTEST_INC),$(GTEST_INC)/gtest/gtest.h)))
HAS_GTEST  := $(if $(GTEST_H),yes,no)

# --- Sources ----------------------------------------------------------------

TEST_SRCS := $(SRC_DIR)/test_git.cc \
             $(SRC_DIR)/test_multiset.cc \
             $(SRC_DIR)/tests_tiltiset.cc
TEST_BINS := $(addprefix $(BIN_DIR)/,$(basename $(notdir $(TEST_SRCS))))

# A throwaway TU used to syntax-check every library header at once.
CHECK_SRC := $(BUILD_DIR)/check_headers.cc
CHECK_BIN := $(BUILD_DIR)/check_headers

# gtest include dirs that actually exist, as -isystem flags.
ISYSTEM := $(addprefix -isystem ,$(sort $(dir $(GTEST_H))))
ISYSTEM := $(patsubst %/gtest/,%,$(ISYSTEM))

# --- Recipes ----------------------------------------------------------------

.PHONY: all check-headers test_git test_multiset tests_tiltiset \
        install uninstall clean help

all: check-headers
	@if [ "$(HAS_GTEST)" = "yes" ]; then \
		$(MAKE) --no-print-directory tests; \
	else \
		echo ">> GoogleTest not found — skipping tests (set GTEST_INC to use it)"; \
	fi

tests: $(TEST_BINS)

$(BIN_DIR) $(BUILD_DIR):
	@mkdir -p $@

$(TEST_BINS): $(BIN_DIR) $(BUILD_DIR)

$(BIN_DIR)/%: $(SRC_DIR)/%.cc $(LIB_HEADERS)
	$(CXX) $(CXXFLAGS) $(ISYSTEM) -I$(SRC_DIR) $< -o $@ $(GTEST_LIBS)

# Individual test binaries (nice for running one at a time).
test_git: $(BIN_DIR)/test_git
test_multiset: $(BIN_DIR)/test_multiset
tests_tiltiset: $(BIN_DIR)/tests_tiltiset

check-headers: $(BUILD_DIR) $(CHECK_SRC) $(LIB_HEADERS)
	$(CXX) $(CXXFLAGS) -I$(SRC_DIR) -fsyntax-only $(CHECK_SRC)

$(CHECK_SRC): | $(BUILD_DIR)
	@printf '%s\n' \
	    '#include "set.h"' \
	    '#include "map.h"' \
	    '#include "multiset.h"' \
	    'int main() { return 0; }' > $@

# --- Installation -----------------------------------------------------------

install: $(LIB_HEADERS)
	install -d $(INSTALL_DIR)
	install -m 644 $^ $(INSTALL_DIR)
	@echo ">> headers installed to $(INSTALL_DIR)"

uninstall:
	rm -rf $(INSTALL_DIR)
	@echo ">> removed $(INSTALL_DIR)"

# --- Maintenance ------------------------------------------------------------

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

help:
	@echo "Targets:"
	@echo "  all             header check + tests (tests need GoogleTest)"
	@echo "  check-headers   compile-only check of set/map/multiset headers"
	@echo "  test_git        build bin/test_git"
	@echo "  test_multiset   build bin/test_multiset"
	@echo "  tests_tiltiset  build bin/tests_tiltiset"
	@echo "  install         install headers to \$$(PREFIX)/include/s21"
	@echo "  uninstall       remove installed headers"
	@echo "  clean           remove build/ and bin/"
	@echo ""
	@echo "Variables:"
	@echo "  CXX             compiler        (default: g++)"
	@echo "  FATAL_WARNINGS  yes -> add -Werror"
	@echo "  GTEST_INC       path to google test root (auto-detected)"
	@echo "  PREFIX          install prefix  (default: /usr/local)"