# This file is a part of Julia. License is MIT: https://julialang.org/license

"""
Multithreading support.
"""
module Threads

global Condition # we'll define this later, make sure we don't import Base.Condition

if Base.DISABLE_THREADS
    threadid() = 1
    nthreads() = 1
else
    include("threadingconstructs.jl")
    include("atomics.jl")
    include("locks-mt.jl")
end

end
