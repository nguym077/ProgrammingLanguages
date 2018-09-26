% Marian Nguyen
% September 27, 2018
% CECS 424
% Lab 1: Puzzling Prolog

% module used to use 'ins' and 'all_distinct'
:- use_module(library(clpfd)).

% sum_list finds the sum of a list of integers
% sum_list([1,3,5], S) should give S=9
sum_list([], 0).
sum_list([H|T], Sum):- sum_list(T, S2), Sum #= H + S2.

% product_list finds the product of a list of integers
% product_list([3,2,3], M) should give M=18
product_list([], 1).
product_list([H|T], Ans):- product_list(T, M), Ans #= H * M.

% cell_values(Cells, S, Values) translates a list of coordinates into a
% list of values at those coordinates.
% Given S whose first row contains the values 2, 1, then
% cell_values([[0,0], [0,1]], S, Values) would give Values = [2,1]
cell_values([], _S, []).
cell_values([[X,Y]|T], S, Values):-
    nth0(X, S, Row),  			% uses coordinates to grab S values (V2)
    nth0(Y, Row, V),
    append([V], V2, Values),  	% appends value to solution list (could also use Values = [V|V2])
    cell_values(T, S, V2).	% repeat until Cells is empty list

% check_constraint (id): true iff the exact value of the single entry in Cells = V
check_constraint(cage(id, V, Cells), S):-
    cell_values([Cells], S, Values),
    V =:= Values.

% check_constraint (add): true iff the entries in Cells sum to V
check_constraint(cage(add, V, Cells), S):-
    cell_values(Cells, S, Values),
    sum_list(Values, Sum),
    V =:= Sum.

% check_constraint (sub): true iff the two entries in Cells equal to V
% ***** COULD CAUSE PROBLEMS. CHECK LATER!
check_constraint(cage(sub, V, Cells), S):-
    cell_values(Cells, S, [X, Y|_T]),
    (V =:= X - Y; V =:= Y - X).

% check_constraint (div): true iff the quotient of the two entries in Cells equal to V
% **** COULD CAUSE PROBLEMS. CHECK LATER!
check_constraint(cage(div, V, Cells), S):-
    cell_values(Cells, S, [X, Y|_]),
    (V =:= X // Y; V =:= Y // X).

% check_constraint (mult): true iff the entries in Cells have a product equal to V
check_constraint(cage(mult, V, Cells), S):-
    cell_values(Cells, S, Values),
    product_list(Values, P),
    V =:= P.

% check_cages: true iff entries in S satisfy the cages of the puzzle
check_cages([], _S).
check_cages([H|T], S):-
    check_constraint(H, S),
    check_cages(T, S).

solve(Cages, S):-
    % forces 'S' to have 6 rows
    length(S, 6),

    % forces row to have distinct values between 1 and 6
    append(Rows, Values),
    Values ins 1..6,
    maplist(all_different, Rows),

    % forces row to have distinct values between 1 and 6
    transpose(Rows, Cols),
    maplist(all_different, Cols),

    % sets up cages in kenken puzzle
    Cages = [cage(mult, 120, [[0,0], [0,1], [1,0], [2,0]]),
             cage(div, 2, [[1,1], [2,1]]),
             cage(mult, 15, [[3,0], [3,1]]),
             cage(sub, 3, [[4,0], [5,0]]),
             cage(sub, 1, [[4,1], [4,2]]),
             cage(sub, 5, [[5,1], [5,2]]),
             cage(mult, 144, [[0,2], [1,2], [1,3], [1,4]]),
             cage(sub, 3, [[2,2], [3,2]]),
             cage(id, 4, [0,3]),
             cage(sub, 4, [[2,3], [2,4]]),
             cage(add, 16, [[3,3], [3,4], [4,3], [5,3]]),
             cage(add, 6, [[0,4], [0,5]]),
             cage(div, 3, [[1,5], [2,5]]),
             cage(mult, 48, [[3,5], [4,5], [4,4]]),
             cage(mult, 6, [[5,4], [5,5]])],

    % empty kenken puzzle, S
    % S = [[_,_,_,_,_,_],
    % 		[_,_,_,_,_,_],
    % 		[_,_,_,_,_,_],
    % 		[_,_,_,_,_,_],
    % 		[_,_,_,_,_,_],
    % 		[_,_,_,_,_,_]]

    % checks all cages in S
    check_cages(Cages, S),

    maplist(label, Rows).

% [cage(sub, 1, [[0,0],[0,1]]), cage(id, 3, [0,2]), cage(add, 9, [[1,0],[1,1],[2,0],[2,1]]), cage(div, 2, [[1,2],[2,2]])]
% [[1,2,3],[3,1,2],[2,3,1]]

% creates irregular "cages" in KenKen puzzle
% cage(mult, 120, [[0,0], [0,1], [1,0], [2,0]]).
% cage(div, 2, [[1,1], [2,1]]).
% cage(mult, 15, [[3,0], [3,1]]).
% cage(sub, 3, [[4,0], [5,0]]).
% cage(sub, 1, [[4,1], [4,2]]).
% cage(sub, 5, [[5,1], [5,2]]).
% cage(mult, 144, [[0,2], [1,2], [1,3], [1,4]]).
% cage(sub, 3, [[2,2], [3,2]]).
% cage(id, 4, [0,3]).
% cage(sub, 4, [[2,3], [2,4]]).
% cage(add, 16, [[3,3], [3,4], [4,3], [5,3]]).
% cage(add, 6, [[0,4], [0,5]]).
% cage(div, 3, [[1,5], [2,5]]).
% cage(mult, 48, [[3,5], [4,5], [4,4]]).
% cage(mult, 6, [[5,4], [5,5]]).
