lay n
lay n
lay n
lay n
lay n
break http_message
run ./test0.txt

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