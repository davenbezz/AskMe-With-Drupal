(function ($) {

  Drupal.behaviors.answerSetting = {
    attach: function (context) {
      // Provide the vertical tab summaries.
      $('fieldset#edit-display', context).drupalSetSummary(function (context) {

        var details = [];
        if ($('#edit-answers-redirect-from-answer-to-question-nodes-p', context).attr('checked') === true ) {
          details.push('Redirect Answer to Question');
        }

        if ($('#edit-answers-hide-question-reference-field', context).attr('checked') === true) {
          details.push('<em>Hide</em> question field');
        } else {
          details.push('<em>Show</em> question field');
        }

        return details;
      });
    }
  };

})(jQuery);
