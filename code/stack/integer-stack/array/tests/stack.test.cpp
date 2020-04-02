#include <catch/catch.hpp>
#include <stdexcept>

#include "stack.hpp"

SCENARIO( "Creating an integer stack", "[stack]" )
{
    GIVEN( "An empty stack" )
    {
        Stack stack;

        REQUIRE( stack.size() == 0 );
        REQUIRE( stack.capacity() == 32 );
    }

    GIVEN( "A stack with set capacity" )
    {
        Stack stack{11};

        REQUIRE( stack.size() == 0 );
        REQUIRE( stack.capacity() == 11 );
    }
}

SCENARIO( "Pushing a value into the stack", "[stack]" )
{
    GIVEN( "An empty stack" )
    {
        Stack stack;

        WHEN( "A value is pushed into the stack" )
        {
            REQUIRE( stack.push( 7 ) == true );

            THEN( "The size increases" )
            {
                REQUIRE( stack.size() == 1 );
            }
        }
    }

    GIVEN( "A stack with one item" )
    {
        Stack stack;

        REQUIRE( stack.push( 7 ) == true );

        WHEN( "A value is pushed into the stack" )
        {
            REQUIRE( stack.push( 19 ) == true );

            THEN( "The size increases" )
            {
                REQUIRE( stack.size() == 2 );
            }
        }
    }
}

SCENARIO( "Accessing the top value", "[stack]" )
{
    GIVEN( "An empty stack" )
    {
        Stack stack;

        REQUIRE_THROWS_AS( stack.top(), std::out_of_range );
    }

    GIVEN( "A stack with one item" )
    {
        Stack stack;

        stack.push( 5 );

        REQUIRE_NOTHROW( stack.top() );

        REQUIRE( stack.top() == 5 );
    }
}

SCENARIO( "Removing the top value", "[stack]" )
{
    GIVEN( "An empty stack" )
    {
        Stack stack;

        WHEN( "Popping the top value" )
        {
            auto const old_size = stack.size();
            auto const old_capacity = stack.capacity();

            int popped_value;

            REQUIRE_NOTHROW( popped_value = stack.pop() );

            REQUIRE( popped_value == 0 );

            THEN( "Size and capacity should remain unchanged" )
            {
                REQUIRE( stack.size() == old_size );
                REQUIRE( stack.capacity() == old_capacity );
            }
        }
    }

    GIVEN( "A stack with one item" )
    {
        Stack stack;
        int const original_value{5};

        stack.push( original_value );

        WHEN( "Popping the top value" )
        {
            auto const old_size = stack.size();
            auto const old_capacity = stack.capacity();

            int const popped_value = stack.pop();

            REQUIRE( popped_value == original_value );

            THEN( "Size should be decremented" )
            {
                REQUIRE( stack.size() == ( old_size - 1 ) );
            }

            THEN( "Capacity should remain unchanged" )
            {
                REQUIRE( stack.capacity() == old_capacity );
            }
        }
    }
}
