set(PrimeBreakdown_SRC
    prime_breakdown_core.cpp
    )

# Form the full path to the source files...
PREPEND(PrimeBreakdown_SRC)
# ... and pass the variable to the parent scope.
set(PrimeBreakdown_SRC ${PrimeBreakdown_SRC}  PARENT_SCOPE)