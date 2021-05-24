# markstos Corne (CRKBD) keyyboard layout 

## TODO

 * Target audience: new to Corne and QMK.
   * This is the README I always wanted.
 * It's about the flow
 * But how fast can you type ??
  * 90 wpm
  * 60 wpm for code
   * If you've never tested your typing code on a block of code, don't assume that
     your typing speed for regular text is a "good baseline".

 * Why 40%?
 * Why Corne?
 * Holding both Raise and Lower activates Adjust
 * Why not:
    * No LEDs
    * No OLEDS
    * No encoder knobs
    * No mouse key bindings.


## Design goals

* A minimal number of keystrokes should be required.
  * To support this, common symbols are added to the base layer. The `-` occurs frequently
    for terminal work and '=' is common as well.
  * Minimize the need for three-key combos. Most things should be done by two-key combos.
  * Minimize the need "adjust" layer that requires two thumbs to access.
 * Minimize awkward hand positions and speed up typing by using one-shot monitors for common
   modifiers: Shift and control.
 * Shift some work from weaker pinkies to strong thumbs by moving enter, backspace, and right
   shift to thumb keys.
 * Thumbs should rest on the most common keys they will be used for: Enter and Space.
 * Be similar enough to conventional laptop keyboards so that switching back and forth is not too
   painful
 * Vim-friendly features:
    * HJKL arrow keys work in any app
    * Escape on base layer through JK combo.
 * Media keys: Play/Pause, Prev/Next, Vol Up/Down are all provided.
 * Function keys needs to present but easily accessible.
 * RGB lighting adjustment keys
 * Numbers and Symbols on the same layer to make easy to type strings of numbers and dates.
   * The "colon" key is repeated on the number layer to make it easy to type dates.
 * Make less common navigation keys easier to access: Home, End, Page Up, Page Down. The lesser
   known "app" key is useful for showing context menus via keyboard that are usually shown with
   a right click.
 * Friendly for tiling window managers
  * The "Super" key is conveniently accessible on a thumb.
 * Just for fun, test out "Copy" and "Paste" keycodes

## Summary of layout

 * Most functionality on  3 layers: Qwerty, Number/Symbols, and Navigation. A fourth later
   for adjustments is rarely used.
 * RGB lighting support worked in the past but is currently disabled. Lights were novel
   but distracting the two halves would get stuck out of sync. They keyboard is so small,
   with every key easy to reach, so there's little reason to look at it, even in the dark.
 * OLED display support has been disabled to save space in the firmware. See point above.
 * Several key chord combos are used. More on those below.

## Keychord Combos

Several key-chords are programmed to emit key codes, which QMK calls combos.

These mostly go unused because they are slower or less accurate to type than the alternatives.
None of the combos are required. However, they are fun to use sometimes and are rarely typed
by accident so I leave them in the layout.

The goal was to bring some the symbols I use more commonly to the base layer.

The combo I use the most is "JK" to emit "Escape". Inside Vim, something similar can be
configured with `inoremap jk <esc>`. However, I frequently use Vim on remote machines where
my custom `.vimrc` is not present. I love having this in the keyboard for those occasions.

For coding, I also made parens, brackets and braces available on the base layer. I realized
that I could fairly reliably press the inner pairs two columns of keys with a single figure by
pressing the space in between the two keys. With the shape of MT3 key caps, it's very easy
to feel if your fingers are in the "bowl" of a single key or on the ridges between two keys.
Essentially this adds a hidden extra column of keys!

### Braces, Parens and Bracket Combos to be pressed with a single finger

These are all symmetric-- the combos for the open and closing elements are mirrored on the
left and right halves of the split keyboard:

 * RT -> [, YU -> ]
 * FG -> (, HJ -> )
 * VB -> {, NM -> }

 To remember the order, think of them getting going from flat to curvy from top to bottom.

### Forward and Backslash Combos: visualizing drawing slashes with your hands

The forward and backslash combos are also mirrored making them easier to remember.


  * RM -> \ Visualize a line from the R key to the M keys making a back slash shape.
  * VU -> / Visualize a line from the V key to the U keys making a forward slash shape.

### Home row backspace 

Because backspace is so commonly used, I put it under an FJ combo. However, I've
abandoned this combo in favor of backspace-on-thumb key that's also on the base layer.

## How to type combinations like Control-Alt-4

The thumb key that would otherwise hold the Alt key is busy holding the number layer key so
home row ALT modifiers are included in the number row under the F and J keys to help with this.

However, these have been abandoned in favor using one-shot modifiers. If I want to type Control-Alt-4,

I would tap the Control key, tap the Alt key, then hold the number layer modifier and type "4".
This is more comfortable to type and doesn't require remembering the alternate "Alt" key locations.

## Benefits of a thumb shift key

Thumb shift key shines when typing an all caps word. With pinkie-shift,
normally you switch and forth between the left and right shift
key depending on which character is being type, and typing an ALLCAPS word would mean double the number
of keystrokes as Shift is typed for each character.

To type an ALLCAPS key with this layout, just hold down the thumb-shift key, type the whole word and
release-- the thumb shift works when typing with either hand.

## Benefits of a number layer

Typing a single number here and there is arguably faster with a dedicated
number row.  But numbers often come in clusters, like a date (01/02/2020), a
time (12:04) or a cost: ($1,234.05).  As you get into typing a string of keys
on a dedicated number row, the whole hand moves up the number row and you've
lost the grounding of the home row. Typing "$4" isn't particularly convenient
because the "$" and "4" on the same key.

In this layout, just hold the thumb on the number/symbol layer, type the whole stream of numbers
of numbers and symbols with your hands comfortably on the home row the whole time and release.
The colon is repeated on the number row to help type dates like this.

Typing "$4" is no problem as the numbers and their shifted symbols are broken out with unique
key codes.

## Navigation layer: More than just arrow keys

In addition to arrow keys, the navigation layer also includes Home, End, Page Up, Page Down
and the App key. On my conditional keyboard I avoided using those keys because they were inconvenient
to access. But they are supported in nearly every application so the navigation layer gives you
home row superpowers to navigate through documents.

The "Home" and "End" pair are placed next to each other Home coming before End, while Page Up
is place above Page Down.

When you misspell a word and see the red underline appear, the App key is perfect for that case.
Use the home row arrow keys to move the cursor back and press the App key just to the right of
the arrow keys. The context menu with spelling options will appear and you can use the arrow keys to
select your option. Done? Use the End key to return back to the end of the line.

The whole sequence can be done holding down the thumb key for the Navigation layer and staying on
that layer.

If you need to select text during this process, the left one-shot Shift can be used for this.
While the right shift key is unavailable due to the right thumb holding down a different key.

The navigation layer also contains "Copy" and "Paste" keycodes. These are useful in terminal
apps where "Control-C" and "Control-V" are reserved by the shell, so "Shift-Control-C" and
"Shift-Control-V" are typically used instead. By using the navigation layer instead,
Copy and Paste returns to being a two-key job. Also, as long your favorite apps support
these uncommon keycodes, you can use the same copy/paste shortcuts everywhere instead of
remembering that the terminal requires an exceptional combo.


## Any regrets or weaknesses?

I use the Control+Super prefix a lot with my window manager. It might be nice to have
a single keypress for that. Perhaps Tap Dance could be used that a "Tap Hold" of the
either the Control or Super key emits Control+Super










