#pragma once

#include <string>

/** Replaces ODBC escape-sequences to form a ClickHouse-compatible SQL-dialect.
 *
 * In case of error, the input is returned as-is, with no modifications.
 */
std::string replaceEscapeSequences(const std::string & query);
