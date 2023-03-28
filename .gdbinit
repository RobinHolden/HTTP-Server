lay n
lay n
lay n
lay n
lay n
break message
run tests/testFile/test0.txt mot

define printTree 
    p *root
    set $node = (*root)->child
    while ($node != 0x0)
        p *($node)
        set $node = ($node)->sibling
    end
end

set trace-commands on
set logging on