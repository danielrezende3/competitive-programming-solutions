The parent event has no Project Code or 3 Digit Project Code. If a parent event has children events, then its 3 Digit Project Code must updated to:

- [ ] ???, if the children don't have the same 3 Digit Project Code, or
- [ ] The 3 Digit Project Code of its children. 

There are some conditions to exclude the events from the records, these are:

- [ ] Any parent event without children should be exclude from the output.
- [ ] All serialized sets that don't have a unique parent event should be eliminated from the output.
- [ ] Any record with no acronym is eliminated from the output.
- [ ] Any child event without a parent should be eliminated from the output. 

Case is important when comparing acronyms. Rat, RAT, RaT, etc. are all different acronyms. 