set(PrimeBreakdown_INC
    prime_breakdown_core.h
    )

# Form the full path to the source files...
PREPEND(PrimeBreakdown_INC)
# ... and pass the variable to the parent scope.
set(PrimeBreakdown_INC ${PrimeBreakdown_INC}  PARENT_SCOPE)